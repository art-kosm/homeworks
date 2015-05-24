#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "calculator.h"

class CalculatorTest : public QObject
{
    Q_OBJECT

public:
    explicit CalculatorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        calculator = new Calculator();
    }

    void cleanup()
    {
        delete calculator;
    }

    void testAddition()
    {
        double result = calculator->calculate(14, 26, "+");

        QVERIFY(result == 40);
    }

    void testSubtraction()
    {
        double result = calculator->calculate(-20, -36, "-");

        QVERIFY(result == 16);
    }

    void testMultiplication()
    {
        double result = calculator->calculate(25, -25, "*");

        QVERIFY(result == -625);
    }

    void testDivision()
    {
        double result = calculator->calculate(3, 14, "/");

        QVERIFY(result == (double) 3/14);
    }

    void testExponentiation()
    {
        double result = calculator->calculate(4, 3, "^");

        QVERIFY(result == 64);
    }

private:
    Calculator *calculator;
};
