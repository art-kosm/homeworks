#pragma once

#include <QDialog>
#include <QTcpSocket>
#include "../message_exchanger/messageExchanger.h"

class QComboBox;
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPlainTextEdit;
class QPushButton;
class QNetworkSession;

class Client : public QDialog
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);
    ~Client();

private slots:
    void sessionOpened();
    void connectToHost();
    void sendMessage();
    void getMessage();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    QNetworkSession *networkSession;
    QTcpSocket *tcpSocket;
    MessageExchanger *exchanger;

    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QLabel *statusLabel;
    QPlainTextEdit *chat;
    QLineEdit *userMessage;

    void setWidgets();
    void openSession();
};
