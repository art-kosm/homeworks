#include <iostream>
#include <QApplication>
#include "ticTacToeGameTest.h"
#include "mainWindow.h"

int main(int argc, char *argv[])
{
    TicTacToeGameTest testGame;
    QTest::qExec(&testGame);
    std::cout << std::endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
