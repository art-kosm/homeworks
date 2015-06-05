#include <QApplication>
#include "mainWindow.h"
#include "linkedListTest.h"
#include "hashtableTest.h"

int main(int argc, char *argv[])
{
    LinkedListTest testList;
    QTest::qExec(&testList);

    printf("\n");

    HashtableTest testHashtable;
    QTest::qExec(&testHashtable);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
