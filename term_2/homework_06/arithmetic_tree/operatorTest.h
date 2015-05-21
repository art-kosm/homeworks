#pragma once

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

    void testOperatorAdd()
    {
        operation = new OperatorAdd;

        QVERIFY(operation->get() == '+');
    }

    void testOperatorSub()
    {
        operation = new OperatorSub;

        QVERIFY(operation->get() == '-');
    }

    void testOperatorMul()
    {
        operation = new OperatorMul;

        QVERIFY(operation->get() == '*');
    }

    void testOperatorDiv()
    {
        operation = new OperatorDiv;

        QVERIFY(operation->get() == '/');
    }

private:
    Operator *operation;
};
