#pragma once

#include <cstdlib>
#include <ctime>
#include <QObject>
#include <QtTest/QtTest>
#include "number.h"
#include "tree.h"
#include "operatorAdd.h"

class OperandTest : public QObject
{
    Q_OBJECT

public:
    explicit OperandTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void cleanup()
    {
        delete operand;
    }

    void testNumber()
    {
        srand(time(0));

        int value = rand();
        operand = new Number(value);

        QVERIFY(operand->calculate() == value);
    }

    void testTree(){
        int leftValue = rand();
        int rightValue = rand();

        Tree *tree = new Tree;
        tree->setOperation(new OperatorAdd);
        tree->setLeftOperand(new Number(leftValue));
        tree->setRightOperand(new Number(rightValue));

        operand = tree;

        QVERIFY(operand->calculate() == leftValue + rightValue);
    }

private:
    Operand *operand;
};
