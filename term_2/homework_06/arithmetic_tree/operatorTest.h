#pragma once

#include <cstdlib>
#include <ctime>
#include <QObject>
#include <QtTest/QtTest>
#include "operatorAdd.h"
#include "operatorSub.h"
#include "operatorMul.h"
#include "operatorDiv.h"

class OperatorTest : public QObject
{
    Q_OBJECT

public:
    explicit OperatorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void cleanup()
    {
        delete operation;
    }

    void testOperatorAddGet()
    {
        operation = new OperatorAdd;

        QVERIFY(operation->get() == '+');
    }

    void testOperatorAddCalculate()
    {
        operation = new OperatorAdd;
        int left = rand();
        int right = rand();

        QVERIFY(operation->calculate(left, right) == left + right);
    }

    void testOperatorSubGet()
    {
        operation = new OperatorSub;

        QVERIFY(operation->get() == '-');
    }

    void testOperatorSubCalculate()
    {
        operation = new OperatorSub;
        int left = rand();
        int right = rand();

        QVERIFY(operation->calculate(left, right) == left - right);
    }

    void testOperatorMulGet()
    {
        operation = new OperatorMul;

        QVERIFY(operation->get() == '*');
    }

    void testOperatorMulCalculate()
    {
        operation = new OperatorMul;
        int left = rand();
        int right = rand();

        QVERIFY(operation->calculate(left, right) == left * right);
    }

    void testOperatorDivGet()
    {
        operation = new OperatorDiv;

        QVERIFY(operation->get() == '/');
    }

    void testOperatorDivCalculate()
    {
        operation = new OperatorDiv;
        int left = rand();
        int right = rand() + 1;

        QVERIFY(operation->calculate(left, right) == left / right);
    }

private:
    Operator *operation;
};
