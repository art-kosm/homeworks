#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "listsComparator.h"

class ListsComparatorTest : public QObject
{
    Q_OBJECT

public:
    explicit ListsComparatorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        comparator = new ListsComparator();
        list1 = new LinkedList();
        list2 = new LinkedList();
    }

    void cleanup()
    {
        delete comparator;
        delete list1;
        delete list2;
    }

    void testEmptyLists()
    {
        QVERIFY(!comparator->isGreaterThan(list1, list2));
    }

    void testOneElementList1()
    {
        list1->insert(35);

        QVERIFY(comparator->isGreaterThan(list1, list2));
    }

    void testOneElementList2()
    {
        list2->insert(-7);

        QVERIFY(!comparator->isGreaterThan(list1, list2));
    }

    void testEqualLists()
    {
        for (int i = 0; i < 10; i++)
        {
            list1->insert(i);
            list2->insert(-i);
        }

        QVERIFY(!comparator->isGreaterThan(list1, list2));
    }

    void testList1IsLonger()
    {
        for (int i = 0; i < 7; i++)
        {
            list1->insert(5);
            if (i > 3)
                list2->insert(-3);
        }

        QVERIFY(comparator->isGreaterThan(list1, list2));
    }

    void testList1IsShorter()
    {
        for (int i = 0; i < 6; i++)
        {
            if (i > 1)
                list1->insert(i - 1);
            list2->insert(i + 1);
        }

        QVERIFY(!comparator->isGreaterThan(list1, list2));
    }

private:
    ListsComparator *comparator;
    LinkedList *list1;
    LinkedList *list2;
};
