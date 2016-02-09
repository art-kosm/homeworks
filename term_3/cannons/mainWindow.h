#pragma once

#include <QMainWindow>
#include <QtNetwork>
#include "gameArea.h"
#include "messageExchanger.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void shellSelected(int);

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void updateArea();
    void singlePlayerGameSelected();
    void serverSelected();
    void clientSelected();
    void setPort(QString portString);
    void connectToHost();
    void acceptConnection();
    void sendMessage(QString message);
    void sendMessage(int message);
    void getMessage();

private:
    Ui::MainWindow *ui;
    GameArea *area;
    bool landSet;

    int port;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    MessageExchanger *exchanger;
};
