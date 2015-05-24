#include "mainWindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    calculator = new Calculator();

    connect(ui->spinBoxNumber1, SIGNAL(valueChanged(int)), this, SLOT(compute()));
    connect(ui->spinBoxNumber2, SIGNAL(valueChanged(int)), this, SLOT(compute()));
    connect(ui->comboBoxOperator, SIGNAL(activated(int)), this, SLOT(compute()));

    connect(ui->spinBoxNumber1, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxValueChanged()), Qt::QueuedConnection);
    connect(ui->spinBoxNumber2, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxValueChanged()), Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{
    delete calculator;
    delete ui;
}

void MainWindow::compute()
{
    int firstArgument = ui->spinBoxNumber1->value();
    int secondArgument = ui->spinBoxNumber2->value();
    QString operation = ui->comboBoxOperator->currentText();

    double result = calculator->calculate(firstArgument, secondArgument, operation);

    ui->lineEditResult->setText(QString::number(result));
}

void MainWindow::onSpinBoxValueChanged()
{
    ui->spinBoxNumber1->findChild<QLineEdit*>()->deselect();
    ui->spinBoxNumber2->findChild<QLineEdit*>()->deselect();
}
