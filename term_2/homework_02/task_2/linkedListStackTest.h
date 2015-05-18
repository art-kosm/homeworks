#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "linkedListStack.h"

class LinkedListStackTest : public QObject
{
    Q_OBJECT

public:
    explicit LinkedListStackTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        stack = new LinkedListStack();
    }

    void cleanup()
    {
        delete stack;
    }

    void testEmpty()
    {
        QVERIFY(stack->isEmpty());
    }

    void testNotEmpty()
    {
        stack->push(1);
        QVERIFY(!stack->isEmpty());
    }

    void testPopEmpty()
    {
        QVERIFY(stack->pop() == 0);
    }

    void testPopNotEmpty()
    {
        stack->push(1);
        stack->push(2);
        QVERIFY(stack->pop() == 2);
    }

    void testPeekEmpty()
    {
        QVERIFY(stack->peek() == 0);
    }

    void testPeekNotEmpty()
    {
        stack->push(1);
        stack->push(2);
        QVERIFY(stack->peek() == 2);
    }

    void testPeekAfterPop()
    {
        stack->push(1);
        stack->push(2);
        stack->pop();
        QVERIFY(stack->peek() == 1);
    }

private:
    LinkedListStack *stack;
};
