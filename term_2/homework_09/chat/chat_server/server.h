#pragma once

#include <QDialog>

class QLabel;
class QTcpServer;
class QNetworkSession;
class QLineEdit;
class QTcpSocket;

class Server : public QDialog
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);

private slots:
    void sessionOpened();
    void acceptConnection();
    void sendMessage();
    void getMessage();

private:
    QLineEdit *serverMessage;
    QLineEdit *clientMessage;
    QLabel *statusLabel;

    QTcpServer *tcpServer;
    QNetworkSession *networkSession;

    QTcpSocket *tcpSocket;
};
