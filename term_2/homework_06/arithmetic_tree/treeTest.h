#pragma once

#include <cstdlib>
#include <ctime>
#include <QObject>
#include <QtTest/QtTest>
#include "number.h"
#include "tree.h"
#include "operatorAdd.h"
#include "operatorSub.h"
#include "operatorMul.h"
#include "operatorDiv.h"

class TreeTest : public QObject
{
    Q_OBJECT

public:
    explicit TreeTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        tree = new Tree;
    }

    void cleanup()
    {
        delete tree;
    }

    void testNumberAddition()
    {
        srand(time(0));

        int leftValue = rand();
        int rightValue = rand();

        tree->setOperation(new OperatorAdd);
        tree->setLeftOperand(new Number(leftValue));
        tree->setRightOperand(new Number(rightValue));

        QVERIFY(tree->calculate() == leftValue + rightValue);
    }

    void testNumberSubtraction()
    {
        int leftValue = rand();
        int rightValue = rand();

        tree->setOperation(new OperatorSub);
        tree->setLeftOperand(new Number(leftValue));
        tree->setRightOperand(new Number(rightValue));

        QVERIFY(tree->calculate() == leftValue - rightValue);
    }

    void testNumberMultiplication()
    {
        int leftValue = rand();
        int rightValue = rand();

        tree->setOperation(new OperatorMul);
        tree->setLeftOperand(new Number(leftValue));
        tree->setRightOperand(new Number(rightValue));

        QVERIFY(tree->calculate() == leftValue * rightValue);
    }

    void testNumberDivision()
    {
        int leftValue = rand();
        int rightValue = rand();

        tree->setOperation(new OperatorDiv);
        tree->setLeftOperand(new Number(leftValue));
        tree->setRightOperand(new Number(rightValue));

        QVERIFY(tree->calculate() == leftValue / rightValue);
    }

    void testTreeAsLeftOperand()
    {
        int leftValue = rand();
        int rightValue = rand();
        int numberValue = rand();

        Tree *leftOperand = new Tree;
        leftOperand->setOperation(new OperatorMul);
        leftOperand->setLeftOperand(new Number(leftValue));
        leftOperand->setRightOperand(new Number(rightValue));

        tree->setOperation(new OperatorAdd);
        tree->setLeftOperand(leftOperand);
        tree->setRightOperand(new Number(numberValue));

        QVERIFY(tree->calculate() == leftValue * rightValue + numberValue);
    }

    void testTreeAsRightOperand()
    {
        int numberValue = rand();
        int leftValue = rand();
        int rightValue = rand();

        Tree *rightOperand = new Tree;
        rightOperand->setOperation(new OperatorDiv);
        rightOperand->setLeftOperand(new Number(leftValue));
        rightOperand->setRightOperand(new Number(rightValue));

        tree->setOperation(new OperatorSub);
        tree->setLeftOperand(new Number(numberValue));
        tree->setRightOperand(rightOperand);

        QVERIFY(tree->calculate() == numberValue - leftValue / rightValue);
    }

    void testTreeOperands()
    {
        int leftLeftValue = rand();
        int leftRightValue = rand();
        int rightLeftValue = rand();
        int rightRightValue = rand();

        Tree *leftOperand = new Tree;
        leftOperand->setOperation(new OperatorAdd);
        leftOperand->setLeftOperand(new Number(leftLeftValue));
        leftOperand->setRightOperand(new Number(leftRightValue));

        Tree *rightOperand = new Tree;
        rightOperand->setOperation(new OperatorSub);
        rightOperand->setLeftOperand(new Number(rightLeftValue));
        rightOperand->setRightOperand(new Number(rightRightValue));

        tree->setOperation(new OperatorMul);
        tree->setLeftOperand(leftOperand);
        tree->setRightOperand(rightOperand);

        QVERIFY(tree->calculate() == (leftLeftValue + leftRightValue) * (rightLeftValue - rightRightValue));
    }

private:
    Tree *tree;
};
