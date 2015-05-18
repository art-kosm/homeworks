#include <QGridLayout>
#include "mainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setStyleSheet("background: white");
    setWindowTitle("Calculator");

    calculator = new Calculator();
    showingResult = false;

    drawResultField();

    const int buttonsNumber = 16;
    QPushButton **buttons = drawButtons(buttonsNumber);

    setLayout(buttons, buttonsNumber);
    setMapping(buttons, buttonsNumber);
    connect(this, SIGNAL(clicked(const QString &)), this, SLOT(buttonClicked(const QString &)));
}

MainWindow::~MainWindow()
{
    delete calculator;
    delete ui;
}

void MainWindow::drawResultField()
{
    resultField = new QLineEdit;
    resultField->setReadOnly(true);
    resultField->setStyleSheet("background-color: white;"
                               "font: 18px");
}

QPushButton **MainWindow::drawButtons(const int buttonsNumber)
{
    QPushButton **buttons = new QPushButton*[buttonsNumber];

    for (int i = 0; i < 9; i++)
        buttons[i] = new QPushButton(QString::number(i + 1));

    buttons[9] = new QPushButton("0");
    buttons[10] = new QPushButton(".");
    buttons[11] = new QPushButton("=");
    buttons[12] = new QPushButton("+");
    buttons[13] = new QPushButton("-");
    buttons[14] = new QPushButton("*");
    buttons[15] = new QPushButton("/");

    for (int i = 0; i < buttonsNumber; i++)
    {
        buttons[i]->setMinimumSize(80, 40);
        buttons[i]->setMaximumSize(80, 40);
        buttons[i]->setStyleSheet("QPushButton "
                                  "{"
                                  "color: #330000; "
                                  "font: 17pt; "
                                  "background: #66ffaa; "
                                  "border-radius: 5px; "
                                  "} "
                                  "QPushButton:pressed "
                                  "{"
                                  "background: #ddff88; "
                                  "border-radius: 7px; "
                                  "}"
                                  "QPushButton:hover:!pressed "
                                  "{"
                                  "background: #77ffbb; "
                                  "}");
    }

    return buttons;
}

void MainWindow::setLayout(QPushButton **buttons, const int buttonsNumber)
{
    QGridLayout *layout = new QGridLayout;

    layout->addWidget(resultField, 0, 0, 1, 4);

    for (int i = 0; i < buttonsNumber; i++)
        if (i < 9)
            layout->addWidget(buttons[i], i / 3 + 1, i % 3);
        else if (i < 12)
            layout->addWidget(buttons[i], 4, i - 9);
        else
            layout->addWidget(buttons[i], i - 11, 3);

    ui->centralWidget->setLayout(layout);
}

void MainWindow::setMapping(QPushButton **buttons, const int buttonsNumber)
{
    mapper = new QSignalMapper(this);

    for (int i = 0; i < buttonsNumber; i++)
    {
        connect(buttons[i], SIGNAL(clicked()), mapper, SLOT(map()));
        mapper->setMapping(buttons[i], buttons[i]->text());
    }

    connect(mapper, SIGNAL(mapped(const QString &)), this, SIGNAL(clicked(const QString &)));
}

void MainWindow::buttonClicked(const QString &symbol)
{
    switch (symbol.at(0).cell())
    {
        case '+':
        case '-':
        case '*':
        case '/':
        {
            calculator->setNextOperand(resultField->text());
            resultField->setText(QString::number(calculator->getResult()));
            showingResult = true;
            calculator->setOperation(symbol.at(0).cell());
        } break;

        case '=':
        {
            calculator->setNextOperand(resultField->text());
            resultField->setText(QString::number(calculator->getResult()));
            showingResult = true;
            calculator->setOperation('\0');
        } break;

        case '.':
            if (!resultField->text().contains(QChar('.')))
                resultField->setText(resultField->text() + symbol.at(0).cell());
            break;

        default:
            if (showingResult)
            {
                resultField->setText(QString(symbol.at(0).cell()));
                showingResult = false;
            }
            else
                resultField->setText(resultField->text() + symbol.at(0).cell());
            break;
    }
}
