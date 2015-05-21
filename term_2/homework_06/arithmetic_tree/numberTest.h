#pragma once

#include <cstdlib>
#include <ctime>
#include <QObject>
#include <QtTest/QtTest>
#include "number.h"

class NumberTest : public QObject
{
    Q_OBJECT

public:
    explicit NumberTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testNumber()
    {
        srand(time(0));

        int value = rand();
        number = new Number(value);

        QVERIFY(number->calculate() == value);

        delete number;
    }

private:
    Number *number;
};
