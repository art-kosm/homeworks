#pragma once

#include <QDialog>
#include "../message_exchanger/messageExchanger.h"

class QLabel;
class QTcpServer;
class QNetworkSession;
class QLineEdit;
class QPlainTextEdit;
class QTcpSocket;

class Server : public QDialog
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);
    ~Server();

private slots:
    void sessionOpened();
    void acceptConnection();
    void sendMessage();
    void getMessage();

private:
    QTcpServer *tcpServer;
    QNetworkSession *networkSession;
    QTcpSocket *tcpSocket;
    MessageExchanger *exchanger;

    QLabel *statusLabel;
    QPlainTextEdit *chat;
    QLineEdit *userMessage;

    void setWidgets();
    void openSession();
};
