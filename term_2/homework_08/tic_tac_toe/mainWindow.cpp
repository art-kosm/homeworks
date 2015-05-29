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

    turnX = true;
    firstTurn = false; //after previous game

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
    connect(this, SIGNAL(clicked(int)), this, SLOT(nextTurn(int)));
}

void MainWindow::nextTurn(int buttonNumber)
{
    if (firstTurn)
    {
        setWindowTitle("Tic-tac-toe (single-player edition)");
        for (int i = 0; i < buttonsNumber; i++)
            buttons[i]->setText("");
        firstTurn = false;
    }

    if (buttons[buttonNumber]->text().isEmpty())
        buttons[buttonNumber]->setText(turnX ? "X" : "O");

    turnX = !turnX;

    checkForWinner();
}

void MainWindow::checkForWinner()
{
    QString winner = "";
    if (    horizontalWinner(winner) || verticalWinner(winner) ||
            majorDiagonalWinner(winner) || minorDiagonalWinner(winner) ||
            draw(winner))
    {
        showResults(winner);
    }
}

bool MainWindow::horizontalWinner(QString &winner)
{
    bool sequence = false;

    for (int i = 0; i < buttonsNumber; i += sideLength)
    {
        for (int j = 0; j < sideLength - 1; j++)
        {
            sequence = !buttons[i + j]->text().isEmpty() &&
                       buttons[i + j]->text() == buttons[i + j + 1]->text();
            if (!sequence)
                break;
            winner = buttons[i + j]->text();
        }
        if (sequence)
            break;
    }

    return sequence;
}

bool MainWindow::verticalWinner(QString &winner)
{
    bool sequence = false;
    for (int i = 0; i < sideLength; i++)
    {
        for (int j = 0; j < buttonsNumber - sideLength; j += sideLength)
        {
            sequence = !buttons[i + j]->text().isEmpty() &&
                       buttons[i + j]->text() == buttons[i + j + sideLength]->text();
            if (!sequence)
                break;
            winner = buttons[i + j]->text();
        }
        if (sequence)
            break;
    }

    return sequence;
}

bool MainWindow::majorDiagonalWinner(QString &winner)
{
    bool sequence = false;
    for (int i = 0; i < buttonsNumber - 1; i += sideLength + 1)
    {
        sequence = !buttons[i]->text().isEmpty() &&
                   buttons[i]->text() == buttons[i + sideLength + 1]->text();
        if (!sequence)
            break;
        winner = buttons[i]->text();
    }

    return sequence;
}

bool MainWindow::minorDiagonalWinner(QString &winner)
{
    bool sequence = false;
    for (int i = sideLength - 1; i < buttonsNumber - sideLength; i += sideLength - 1)
    {
        sequence = !buttons[i]->text().isEmpty() &&
                   buttons[i]->text() == buttons[i + sideLength - 1]->text();
        if (!sequence)
            break;
        winner = buttons[i]->text();
    }

    return sequence;
}

bool MainWindow::draw(QString &winner)
{
    bool noEmptyPlaces = true;
    for (int i = 0; i < buttonsNumber && noEmptyPlaces; i++)
        if (buttons[i]->text() == "")
            noEmptyPlaces = false;

    if (noEmptyPlaces)
        winner = "Nobody";

    return noEmptyPlaces;
}

void MainWindow::showResults(const QString &winner)
{
    setWindowTitle(winner + " has won!");

    turnX = true;
    firstTurn = true;
}
