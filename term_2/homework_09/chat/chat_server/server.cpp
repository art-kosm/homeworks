#include <cstdlib>
#include <QtWidgets>
#include <QtNetwork>
#include "server.h"

Server::Server(QWidget *parent)
:   QDialog(parent), tcpServer(0), networkSession(0)
{
    statusLabel = new QLabel;

    QLabel *serverLabel = new QLabel("Your message:");
    QLabel *clientLabel = new QLabel("Client message:");
    serverMessage = new QLineEdit;
    clientMessage = new QLineEdit;
    clientMessage->setReadOnly(true);

    QPushButton *sendButton = new QPushButton("Send");
    QPushButton *quitButton = new QPushButton("Quit");

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

    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(statusLabel, 0, 0);
    mainLayout->addWidget(serverLabel, 1, 0);
    mainLayout->addWidget(serverMessage, 1, 1);
    mainLayout->addWidget(clientLabel, 2, 0);
    mainLayout->addWidget(clientMessage, 2, 1);
    mainLayout->addWidget(sendButton, 3, 0);
    mainLayout->addWidget(quitButton, 3, 1);
    setLayout(mainLayout);

    setWindowTitle("Chat server");
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
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16) 0;
    out << serverMessage->text();
    out.device()->seek(0);
    out << (quint16) (block.size() - sizeof(quint16));

    tcpSocket->write(block);
}

void Server::getMessage()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
        return;

    quint16 blockSize = 0;
    in >> blockSize;

    if (tcpSocket->bytesAvailable() < blockSize)
        return;

    QString currentMessage = "";
    in >> currentMessage;
    clientMessage->setText(currentMessage);
}
