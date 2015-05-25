#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "singlyLinkedList.h"

class SinglyLinkedListTest : public QObject
{
    Q_OBJECT

public:
    explicit SinglyLinkedListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        list = new SinglyLinkedList();
    }

    void cleanup()
    {
        delete list;
    }

    void testEmpty()
    {
        QVERIFY(list->isEmpty());
    }

    void testNotEmpty()
    {
        list->insert(1);
        QVERIFY(!list->isEmpty());
    }

    void testContains()
    {
        list->insert(1);
        list->insert(2);
        list->insert(3);
        QVERIFY(list->contains(2));
    }

    void testDoesNotContain()
    {
        list->insert(1);
        list->insert(2);
        list->insert(3);
        QVERIFY(!list->contains(0));
    }

    void testRemoveExisting()
    {
        list->insert(1);
        list->insert(2);
        list->insert(3);
        list->remove(2);
        QVERIFY(!list->contains(2));
    }

    void testRemoveNotExisting()
    {
        list->insert(1);
        list->remove(0);
        QVERIFY(list->contains(1));
    }

    void testLength()
    {
        list->insert(1);
        list->insert(2);
        list->insert(3);
        list->remove(3);
        QVERIFY(list->getLength() == 2);
    }

private:
    SinglyLinkedList *list;
};
