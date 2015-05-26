#include <QApplication>
#include "calculatorTest.h"
#include "mainWindow.h"

int main(int argc, char *argv[])
{
    CalculatorTest testCalculator;
    QTest::qExec(&testCalculator);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
