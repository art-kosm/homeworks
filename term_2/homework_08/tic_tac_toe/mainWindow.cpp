#include <QGridLayout>
#include <QSignalMapper>
#include "mainWindow.h"
#include "ui_mainWindow.h"

MainWindow::MainWindow(int size, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Tic-tac-toe (single-player edition)");
    setMinimumSize(250, 297);

    game = new TicTacToeGame(size);

    initializeButtons(size);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeButtons(int size)
{
    sideLength = size;
    buttonsNumber = sideLength * sideLength;
    buttons = new QPushButton*[buttonsNumber];

    QSignalMapper *mapper = new QSignalMapper(this);
    QGridLayout *layout = new QGridLayout;

    for (int i = 0; i < buttonsNumber; i++)
    {
        buttons[i] = new QPushButton;
        buttons[i]->setText("");
        buttons[i]->setStyleSheet("QPushButton "
                                  "{"
                                  "color: #330000; "
                                  "font: 52pt; "
                                  "background: #ff6666; "
                                  "border-radius: 5px; "
                                  "} "
                                  "QPushButton:pressed "
                                  "{"
                                  "background: #ffff88; "
                                  "border-radius: 7px; "
                                  "}"
                                  "QPushButton:hover:!pressed "
                                  "{"
                                  "background: #ffffbb; "
                                  "}");
        buttons[i]->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

        layout->addWidget(buttons[i], i / sideLength, i % sideLength);

        connect(buttons[i], SIGNAL(clicked()), mapper, SLOT(map()));
        mapper->setMapping(buttons[i], i);
    }

    ui->centralWidget->setLayout(layout);

    connect(mapper, SIGNAL(mapped(int)), this, SIGNAL(clicked(int)));
    connect(this, SIGNAL(clicked(int)), game, SLOT(nextTurn(int)));
    connect(game, SIGNAL(turnMade(int, FieldValue)), this, SLOT(setTurn(int, FieldValue)));

    connect(game, SIGNAL(gameFinished(GameStatus)), this, SLOT(showResults(GameStatus)));
    connect(game, SIGNAL(newGame()), this, SLOT(resetWindow()));
}

void MainWindow::resetWindow()
{
    setWindowTitle("Tic-tac-toe (single-player edition)");
    for (int i = 0; i < buttonsNumber; i++)
        buttons[i]->setText("");
}

void MainWindow::showResults(GameStatus winner)
{
    switch (winner)
    {
        case crossesWon:
            setWindowTitle("X has won!");
            break;

        case noughtsWon:
            setWindowTitle("O has won!");
            break;

        default:
            setWindowTitle("Draw");
            break;
    }
}

void MainWindow::setTurn(int buttonNumber, FieldValue value)
{
    buttons[buttonNumber]->setText(value == cross ? "X" : "O");
}
