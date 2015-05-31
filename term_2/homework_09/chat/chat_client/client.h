#pragma once

#include <QDialog>
#include <QTcpSocket>

class QComboBox;
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QNetworkSession;

class Client : public QDialog
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);

private slots:
    void sessionOpened();
    void connectToHost();
    void sendMessage();
    void getMessage();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QLabel *statusLabel;

    QTcpSocket *tcpSocket;
    QString currentMessage;
    quint16 blockSize;

    QNetworkSession *networkSession;

    QLineEdit *serverMessage;
    QLineEdit *clientMessage;
};
