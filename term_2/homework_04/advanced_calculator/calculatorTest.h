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

    void testNonNegativeEquals()
    {
        calculator->setNextOperand("5");
        double result = calculator->getResult();

        QVERIFY(result == 5);
    }

    void testNegativeEquals()
    {
        calculator->setNextOperand("-37");
        double result = calculator->getResult();

        QVERIFY(result == -37);
    }

    void testNonIntegerEquals()
    {
        calculator->setNextOperand("-125.47");
        double result = calculator->getResult();

        QCOMPARE(result, -125.47);
    }

    void testIntegerAddition()
    {
        calculator->setNextOperand("42");
        calculator->setOperation('+');
        calculator->setNextOperand("24");
        double result = calculator->getResult();

        QVERIFY(result == 66);
    }

    void testIntegerSubtraction()
    {
        calculator->setNextOperand("19");
        calculator->setOperation('-');
        calculator->setNextOperand("-19");
        double result = calculator->getResult();

        QVERIFY(result == 38);
    }

    void testIntegerMultiplication()
    {
        calculator->setNextOperand("45");
        calculator->setOperation('*');
        calculator->setNextOperand("3");
        double result = calculator->getResult();

        QVERIFY(result == 135);
    }

    void testIntegerDivision()
    {
        calculator->setNextOperand("-29");
        calculator->setOperation('/');
        calculator->setNextOperand("27");
        double result = calculator->getResult();

        QCOMPARE(result, (double) -29 / 27);
    }

    void testNonIntegerAddition()
    {
        calculator->setNextOperand("-5.9");
        calculator->setOperation('+');
        calculator->setNextOperand("6.9");
        double result = calculator->getResult();

        QCOMPARE(result, 1.0);
    }

    void testNonIntegerSubtraction()
    {
        calculator->setNextOperand("29.091");
        calculator->setOperation('-');
        calculator->setNextOperand("-0.9");
        double result = calculator->getResult();

        QCOMPARE(result, 29.991);
    }

    void testNonIntegerMultiplication()
    {
        calculator->setNextOperand("2.2");
        calculator->setOperation('*');
        calculator->setNextOperand("5.95");
        double result = calculator->getResult();

        QCOMPARE(result, 13.09); ///for some reason QVERIFY(result == 13.09) fails here x_x
    }

    void testNonIntegerDivision()
    {
        calculator->setNextOperand("-9.11");
        calculator->setOperation('/');
        calculator->setNextOperand("11.2");
        double result = calculator->getResult();

        QCOMPARE(result, -9.11 / 11.2);
    }

    void testComplexExpression()
    {
        calculator->setNextOperand("12.6");
        calculator->setOperation('/');
        calculator->setNextOperand("2");
        calculator->setOperation('-');
        calculator->setNextOperand("6.3");
        calculator->setOperation('+');
        calculator->setNextOperand("1");
        calculator->setOperation('*');
        calculator->setNextOperand("2");
        double result = calculator->getResult();

        QCOMPARE(result, 2.0);
    }

private:
    Calculator *calculator;
};
