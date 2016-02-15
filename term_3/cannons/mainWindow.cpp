#include <QtWidgets>
#include <QKeyEvent>
#include <QSignalMapper>
#include <QTimer>
#include "mainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    area(new GameArea(this)),
    landSet(true),
    port(0),
    tcpServer(0),
    tcpSocket(new QTcpSocket(this)),
    exchanger(0)
{
    QWidget *openingWidget = new QWidget;
    openingWidget->setWindowTitle("The Cannon");
    openingWidget->setFixedSize(560, 200);
    openingWidget->setStyleSheet("background-color: black;");
    openingWidget->setAttribute(Qt::WA_DeleteOnClose);
    QVBoxLayout *openingWidgetLayout = new QVBoxLayout;
    QPixmap logo("resourses/logo.png");
    QLabel *logoPicture = new QLabel(openingWidget);
    logoPicture->setPixmap(logo);
    openingWidgetLayout->addWidget(logoPicture);
    QGroupBox *gameTypeSelection = new QGroupBox(openingWidget);
    QPalette palette;
    palette.setColor(QPalette::Foreground, Qt::white);
    QVBoxLayout *gameTypeLayout = new QVBoxLayout;
    QRadioButton **gameType = new QRadioButton*[3];

    for (int i = 0; i < 3; i++)
    {
        gameType[i] = new QRadioButton(openingWidget);
        gameType[i]->setPalette(palette);
        gameType[i]->setFont(QFont("Courier New", 12));
        gameType[i]->setStyleSheet("QRadioButton::indicator {border: 1px solid; border-radius: 6px; width: 10px; height: 10px;}"
                                   "QRadioButton::indicator::unchecked {background-color: #000000;}"
                                   "QRadioButton::indicator::hover, QRadioButton::indicator::checked {background-color: #ffff00;}");
        gameTypeLayout->addWidget(gameType[i]);
        connect(gameType[i], SIGNAL(toggled(bool)), openingWidget, SLOT(close()));
    }

    gameType[0]->setText("SINGLEPLAYER");
    gameType[1]->setText("MULTIPLAYER: SERVER");
    gameType[2]->setText("MULTIPLAYER: CLIENT");
    connect(gameType[0], SIGNAL(toggled(bool)), this, SLOT(singlePlayerGameSelected()));
    connect(gameType[1], SIGNAL(toggled(bool)), this, SLOT(serverSelected()));
    connect(gameType[2], SIGNAL(toggled(bool)), this, SLOT(clientSelected()));

    gameTypeSelection->setLayout(gameTypeLayout);
    openingWidgetLayout->addWidget(gameTypeSelection);
    openingWidget->setLayout(openingWidgetLayout);
    openingWidget->show();

    ui->setupUi(this);
    setWindowTitle("The Cannon");
    setFixedSize(640, 480);
    setStyleSheet("background-color: black;");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(area, 1);

    QVBoxLayout *menu = new QVBoxLayout;
    menu->addStretch();
    QPushButton **buttons = new QPushButton*[3];
    QSignalMapper *shellMapper = new QSignalMapper(this);

    for (int i = 0; i < 3; i++)
    {
        buttons[i] = new QPushButton(this);
        buttons[i]->setFixedSize(50, 50);
        QString path = QString("resourses/") + QString::number(i) + QString(".png");
        buttons[i]->setIcon(QIcon(path));
        buttons[i]->setIconSize(QSize(42, 42));
        buttons[i]->setStyleSheet("QPushButton {border-radius: 5px;} "
                                  "QPushButton:pressed {background: #ffff00;} "
                                  "QPushButton:hover:!pressed {background: #00ff00;}");
        connect(buttons[i], SIGNAL(clicked()), area, SLOT(setFocus()));
        menu->addWidget(buttons[i]);
        connect(buttons[i], SIGNAL(clicked()), shellMapper, SLOT(map()));
        shellMapper->setMapping(buttons[i], i);
    }

    connect(shellMapper, SIGNAL(mapped(int)), this, SIGNAL(shellSelected(int)));
    connect(this, SIGNAL(shellSelected(int)), area, SLOT(setShellType(int)));

    menu->addStretch();
    layout->addLayout(menu);
    ui->centralWidget->setLayout(layout);
    area->setFocus();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateArea()));
    timer->start((double) 1000 / 60); // area is automatically updated 60 times per second
}

MainWindow::~MainWindow()
{
    delete ui;
    if (exchanger != nullptr)
        delete exchanger;
}

void MainWindow::singlePlayerGameSelected()
{
    show();
}

void MainWindow::serverSelected()
{
    exchanger = new MessageExchanger;

    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen())
        return;

    port = tcpServer->serverPort();
    area->setPort(port);

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    connect(this, SIGNAL(shellSelected(int)), this, SLOT(sendMessage(int)));

    show();
}

void MainWindow::clientSelected()
{
    landSet = false;

    exchanger = new MessageExchanger;

    QWidget *portWidget = new QWidget;
    portWidget->setWindowTitle("The Cannon");
    portWidget->setFixedSize(300, 50);
    portWidget->setStyleSheet("background-color: white");
    portWidget->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *portLabel = new QLabel("PORT: ", portWidget);
    QFont font("Courier New", 12);
    portLabel->setFont(font);
    portLabel->setStyleSheet("color: black;");

    QLineEdit *portLineEdit = new QLineEdit(portWidget);
    portLineEdit->setFont(font);
    portLineEdit->setStyleSheet("border: black");
    connect(portLineEdit, SIGNAL(textEdited(QString)), this, SLOT(setPort(QString)));

    QPushButton *connectButton = new QPushButton("CONNECT", portWidget);
    connectButton->setFont(font);
    connectButton->setStyleSheet("border: solid; color: black;");
    connect(connectButton, SIGNAL(clicked()), this, SLOT(connectToHost()));
    connect(connectButton, SIGNAL(clicked()), portWidget, SLOT(close()));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(portLabel);
    layout->addWidget(portLineEdit);
    layout->addWidget(connectButton);
    portWidget->setLayout(layout);

    connect(this, SIGNAL(shellSelected(int)), this, SLOT(sendMessage(int)));

    portWidget->show();
}

void MainWindow::setPort(QString portString)
{
    port = portString.toInt();
}

void MainWindow::updateArea()
{
    area->update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Left:
            area->moveCannonToLeft();
            if (port > 0)
                sendMessage("L");
            break;

        case Qt::Key_Right:
            area->moveCannonToRight();
            if (port > 0)
                sendMessage("R");
            break;

        case Qt::Key_Up:
            area->increaseCannonAngle();
            if (port > 0)
                sendMessage("U");
            break;

        case Qt::Key_Down:
            area->decreaseCannonAngle();
            if (port > 0)
                sendMessage("D");
            break;

        case Qt::Key_Return:
            area->cannonFire();
            if (port > 0)
                sendMessage("E");
            break;

        case Qt::Key_1:
            area->setShellType(Small);
            if (port > 0)
                sendMessage("0");
            break;

        case Qt::Key_2:
            area->setShellType(Medium);
            if (port > 0)
                sendMessage("1");
            break;

        case Qt::Key_3:
            area->setShellType(Big);
            if (port > 0)
                sendMessage("2");
            break;
    }
}

void MainWindow::connectToHost()
{
    tcpSocket->abort();
    tcpSocket->connectToHost(QString("Computer"), port);
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(getMessage()));
    show();
}

void MainWindow::acceptConnection()
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(getMessage()));
    sendMessage(area->getLand());
    area->addNewPlayer(area->getPointsNumber() - 3, M_PI - 1, QColor(255, 255, 0));
}

void MainWindow::sendMessage(QString message)
{
    exchanger->sendMessage(tcpSocket, message + QString(" "));
}

void MainWindow::sendMessage(int message)
{
    sendMessage(QString::number(message));
}

void MainWindow::getMessage()
{
    QString result;
    while (tcpSocket->bytesAvailable())
        result += exchanger->getMessage(tcpSocket);

    if (!landSet)
    {
        area->setLand(result);
        landSet = true;
        area->addNewPlayer(2, 1, QColor(0, 255, 0));
    }
    else
        area->interpret(result);
}
