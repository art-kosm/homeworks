#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "sharedPointer.h"

class SharedPointerTest : public QObject
{
    Q_OBJECT

public:
    explicit SharedPointerTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testSinglePointer()
    {
        SharedPointer<int> pointer(new int(5));

        QVERIFY(*pointer == 5);
    }

    void testSinglePointerCount()
    {
        SharedPointer<int> pointer(new int(6));

        QVERIFY(pointer.count() == 1);
    }

    void testMultiplePointersUnchanged()
    {
        SharedPointer<int> pointer1(new int(9));
        SharedPointer<int> pointer2(pointer1);

        QVERIFY(*pointer1 == 9);
    }

    void testMultiplePointersCorrect()
    {
        SharedPointer<int> pointer1(new int(53));
        SharedPointer<int> pointer2(pointer1);

        QVERIFY(*pointer2 == *pointer1);
    }
//change
    void testMultiplePointersCount()
    {
        SharedPointer<int> pointer1(new int(53));
        SharedPointer<int> pointer2(pointer1);

        QVERIFY(pointer1.count() == 2 &&
                pointer2.count() == 2);
    }

    void testChangingPointer()
    {
        SharedPointer<int> pointer1(new int(10));
        SharedPointer<int> pointer2(pointer1);
        SharedPointer<int> pointer3(new int(20));

        pointer2 = pointer3;

        QCOMPARE(pointer1.count(), 1);
        QCOMPARE(pointer2.count(), 2);
        QCOMPARE(pointer3.count(), 2);
        QCOMPARE(*pointer2, *pointer3);

    }
};
