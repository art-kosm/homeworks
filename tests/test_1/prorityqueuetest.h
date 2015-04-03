#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "priorityqueue.h"

class PriorityQueueTest : public QObject
{
    Q_OBJECT

public:
    explicit PriorityQueueTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        queue = new PriorityQueue();
    }

    void cleanup()
    {
        delete queue;
    }

    void testEmpty()
    {
        QVERIFY(queue->dequeue() == INT_MIN);
    }

    void testSingleElement()
    {
        queue->enqueue(1, 2);
        QVERIFY(queue->dequeue() == 1);
    }

    void testMultipleElements()
    {
        queue->enqueue(1, 2);
        queue->enqueue(3, 4);
        queue->enqueue(4, 3);
        QVERIFY(queue->dequeue() == 3);
    }

private:
    PriorityQueue *queue;
};
