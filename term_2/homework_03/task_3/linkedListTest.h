#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "linkedList.h"

class LinkedListTest : public QObject
{
    Q_OBJECT

public:
    explicit LinkedListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        list = new LinkedList();
    }

    void cleanup()
    {
        delete list;
    }

    void testLengthEmpty()
    {
        QVERIFY(list->getLength() == 0);
    }

    void testLengthOneElement()
    {
        list->insert(1);

        QVERIFY(list->getLength() == 1);
    }

    void testLengthManyElements()
    {
        const int size = 100;
        for (int i = 0; i < size; i++)
            list->insert(i - 5);

        QVERIFY(list->getLength() == size);
    }

    void testRemoveExisting()
    {
        list->insert(1);
        list->insert(2);
        list->insert(3);
        list->remove(3);

        QVERIFY(list->getLength() == 2);
    }

    void testRemoveNotExisting()
    {
        list->insert(1);
        list->remove(0);

        QVERIFY(list->getLength() == 1);
    }

    void testInsertManyTimes()
    {
        const int size = 32;
        for (int i = 0; i < size; i++)
            list->insert(1);

        QVERIFY(list->getLength() == size);
    }


private:
    LinkedList *list;
};
