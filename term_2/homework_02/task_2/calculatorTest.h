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
    void cleanup()
    {
        delete calc;
    }

    void testNoInput()
    {
        char expression[] = "";
        calc = new Calculator(expression);
        QVERIFY(calc->calculateExpression() == 0);
    }

    void testSingleNumber()
    {
        char expression[] = "7";
        calc = new Calculator(expression);
        QVERIFY(calc->calculateExpression() == 7);
    }

    void testAddition()
    {
        char expression[] = "7 + 8";
        calc = new Calculator(expression);
        QVERIFY(calc->calculateExpression() == 15);
    }

    void testSubtraction()
    {
        char expression[] = "7 - 8";
        calc = new Calculator(expression);
        QVERIFY(calc->calculateExpression() == -1);
    }

    void testMultiplication()
    {
        char expression[] = "1 + 7 * 8";
        calc = new Calculator(expression);
        QVERIFY(calc->calculateExpression() == 57);
    }

    void testDivision()
    {
        char expression[] = "1 + 7 / 2";
        calc = new Calculator(expression);
        QVERIFY(calc->calculateExpression() == 4);
    }

    void testBrackets()
    {
        char expression[] = "((2 + 2) * 2)";
        calc = new Calculator(expression);
        QVERIFY(calc->calculateExpression() == 8);
    }

    void testComplicated()
    {
        char expression[] = "7+8 / 1-2* (5*9-1/2)";
        calc = new Calculator(expression);
        QVERIFY(calc->calculateExpression() == -75);
    }

private:
    Calculator *calc;
};
