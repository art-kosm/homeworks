#include <QtWidgets>
#include <QtNetwork>

#include "server.h"

Server::Server(QWidget *parent) :
    QDialog(parent),
    tcpServer(0),
    networkSession(0),
    exchanger(new MessageExchanger())
{
    setWidgets();
    setWindowTitle("Chat server");

    openSession();

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

Server::~Server()
{
    delete exchanger;
}

void Server::setWidgets()
{
    statusLabel = new QLabel;

    QLabel *userLabel = new QLabel("Your message:");
    userMessage = new QLineEdit;

    QPushButton *sendButton = new QPushButton("Send");
    QPushButton *quitButton = new QPushButton("Quit");

    QDialogButtonBox *buttonBox = new QDialogButtonBox;
    buttonBox->addButton(sendButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    chat = new QPlainTextEdit();
    chat->setReadOnly(true);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(statusLabel, 0, 0);
    mainLayout->addWidget(chat, 1, 0, 1, 2);
    mainLayout->addWidget(userLabel, 2, 0);
    mainLayout->addWidget(userMessage, 2, 1);
    mainLayout->addWidget(buttonBox, 3, 0, 1, 2);
    setLayout(mainLayout);
}

void Server::openSession()
{
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered)
        {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        statusLabel->setText("Opening network session.");
        networkSession->open();
    }

    else
        sessionOpened();
}

void Server::sessionOpened()
{
    // Save the used configuration
    if (networkSession)
    {
        QNetworkConfiguration config = networkSession->configuration();
        QString id;
        if (config.type() == QNetworkConfiguration::UserChoice)
            id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        else
            id = config.identifier();

        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();
    }

    tcpServer = new QTcpServer(this);

    if (!tcpServer->listen())
    {
        QMessageBox::critical(this, "Chat server",
                              tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        close();
        return;
    }

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    // Use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }

    // If we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                         "Run the chat client now.")
                         .arg(ipAddress).arg(tcpServer->serverPort()));
}

void Server::acceptConnection()
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(getMessage()));
}

void Server::sendMessage()
{
    exchanger->sendMessage(tcpSocket, userMessage->text());
    chat->appendPlainText("server : " + userMessage->text());
}

void Server::getMessage()
{
    chat->appendPlainText("client : " + exchanger->getMessage(tcpSocket));
}
