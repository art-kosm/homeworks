#include <QtWidgets>
#include <QtNetwork>

#include "client.h"

Client::Client(QWidget *parent)
:   QDialog(parent), networkSession(0)
{
    QLabel *hostLabel = new QLabel("Server name:");
    QLabel *portLabel = new QLabel("Server port:");

    hostCombo = new QComboBox;
    hostCombo->setEditable(true);

    // Find out name of this machine
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty())
    {
        hostCombo->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            hostCombo->addItem(name + QChar('.') + domain);
    }

    if (name != QString("localhost"))
        hostCombo->addItem(QString("localhost"));

    // Find out IP addresses of this machine
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    // Add non-localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (!ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }

    // Add localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }

    portLineEdit = new QLineEdit;
    portLineEdit->setValidator(new QIntValidator(1, 65535, this));

    statusLabel = new QLabel("This application requires that you run the "
                             "chat server as well.");

    QLabel *clientLabel = new QLabel("Your message:");
    QLabel *serverLabel = new QLabel("Server message:");
    clientMessage = new QLineEdit;
    serverMessage = new QLineEdit;
    serverMessage->setReadOnly(true);

    QPushButton *connectButton = new QPushButton("Connect");
    QPushButton *sendButton = new QPushButton("Send");
    QPushButton *quitButton = new QPushButton("Quit");

    QDialogButtonBox *buttonBox = new QDialogButtonBox;
    buttonBox->addButton(connectButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(sendButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    tcpSocket = new QTcpSocket(this);

    connect(connectButton, SIGNAL(clicked()), this, SLOT(connectToHost()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(getMessage()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(hostLabel, 0, 0);
    mainLayout->addWidget(hostCombo, 0, 1);
    mainLayout->addWidget(portLabel, 1, 0);
    mainLayout->addWidget(portLineEdit, 1, 1);
    mainLayout->addWidget(clientLabel, 2, 0);
    mainLayout->addWidget(clientMessage, 2, 1);
    mainLayout->addWidget(serverLabel, 3, 0);
    mainLayout->addWidget(serverMessage, 3, 1);
    mainLayout->addWidget(statusLabel, 4, 0, 1, 2);
    mainLayout->addWidget(buttonBox, 5, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle("Chat client");
    portLineEdit->setFocus();

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
}

void Client::sessionOpened()
{
    // Save the used configuration
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

    statusLabel->setText("This application requires that you run the "
                         "chat server as well.");
}

void Client::connectToHost()
{
    blockSize = 0;
    tcpSocket->abort();
    tcpSocket->connectToHost(hostCombo->currentText(),
                             portLineEdit->text().toInt());
}

void Client::sendMessage()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16) 0;
    out << clientMessage->text();
    out.device()->seek(0);
    out << (quint16) (block.size() - sizeof(quint16));

    tcpSocket->write(block);
}

void Client::getMessage()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0)
    {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }

    if (tcpSocket->bytesAvailable() < blockSize)
        return;

    in >> currentMessage;
    serverMessage->setText(currentMessage);

    connectToHost();
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
        case QAbstractSocket::RemoteHostClosedError:
            break;

        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, "Chat client",
                                     "The host was not found. Please check the "
                                     "host name and port settings.");
            break;

        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, "Chat client",
                                     "The connection was refused by the peer. "
                                     "Make sure the fortune server is running, "
                                     "and check that the host name and port "
                                     "settings are correct.");
            break;

        default:
            QMessageBox::information(this, "Chat client",
                                     tr("The following error occurred: %1.")
                                     .arg(tcpSocket->errorString()));
    }
}
