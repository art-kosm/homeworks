#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "sortedSet.h"

class SortedSetTest : public QObject
{
    Q_OBJECT

public:
    explicit SortedSetTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        set = new SortedSet();
    }

    void cleanup()
    {
        delete set;
    }

    void testEmptySet()
    {
        QVERIFY(set->at(0) == nullptr);
    }

    void testEmptyListZeroIndex()
    {
        LinkedList *list = new LinkedList();
        set->insert(list);

        QVERIFY(set->at(0) == list);

        delete list;
    }

    void testEmptyListNonZeroIndex()
    {
        LinkedList *list = new LinkedList();
        set->insert(list);

        QVERIFY(set->at(1) == nullptr);

        delete list;
    }

    void testNonEmptyList()
    {
        LinkedList *list = new LinkedList();
        list->insert(13);
        set->insert(list);

        QVERIFY(set->at(0) == list);

        delete list;
    }

    void testRightOrderLists()
    {
        const int size = 9;
        LinkedList **lists = new LinkedList*[size];
        for (int i = 0; i < size; i++)
        {
            lists[i] = new LinkedList();
            for (int j = 0; j < i; j++)
                lists[i]->insert(j);
        }

        for (int i = 0; i < size; i++)
            set->insert(lists[i]);
        delete [] lists;

        bool orderIsCorrect = true;

        for (int i = 1; i < size && orderIsCorrect; i++)
            if (set->at(i - 1)->getLength() > set->at(i)->getLength())
                orderIsCorrect = false;


        QVERIFY(orderIsCorrect);
    }

    void testReverseOrderLists()
    {
        const int size = 6;
        LinkedList **lists = new LinkedList*[size];
        for (int i = 0; i < size; i++)
        {
            lists[i] = new LinkedList();
            for (int j = 0; j < i * 2; j++)
                lists[i]->insert(j);
        }

        for (int i = size - 1; i >= 0; i--)
            set->insert(lists[i]);
        delete [] lists;

        bool orderIsCorrect = true;

        for (int i = 1; i < size && orderIsCorrect; i++)
            if (set->at(i - 1)->getLength() > set->at(i)->getLength())
                orderIsCorrect = false;

        QVERIFY(orderIsCorrect);
    }

    void testRandomOrderLists()
    {
        const int size = 5;
        LinkedList **lists = new LinkedList*[size];
        for (int i = 0; i < size; i++)
        {
            lists[i] = new LinkedList();
            for (int j = 0; j < i / 2; j++)
                lists[i]->insert(j);
        }

        set->insert(lists[3]);
        set->insert(lists[0]);
        set->insert(lists[1]);
        set->insert(lists[4]);
        set->insert(lists[2]);
        delete [] lists;

        bool orderIsCorrect = true;

        for (int i = 1; i < size && orderIsCorrect; i++)
            if (set->at(i - 1)->getLength() > set->at(i)->getLength())
                orderIsCorrect = false;

        QVERIFY(orderIsCorrect);
    }

    void testCorrectnessOfLists()
    {
        const int size = 3;
        LinkedList **lists = new LinkedList*[size];
        for (int i = 0; i < size; i++)
        {
            lists[i] = new LinkedList();
            for (int j = 0; j < i + 2; j++)
                lists[i]->insert(j);
        }

        set->insert(lists[1]);
        set->insert(lists[0]);
        set->insert(lists[2]);

        QVERIFY(set->at(0) == lists[0] &&
                set->at(1) == lists[1] &&
                set->at(2) == lists[2]);

        delete [] lists;
    }

    void testNoNewElementsInLists()
    {
        const int size = 15;
        LinkedList **lists = new LinkedList*[size];
        int lengths[size];

        for (int i = 0; i < size; i++)
        {
            lists[i] = new LinkedList();
            for (int j = 0; j < i * 3 /2; j++)
                lists[i]->insert(j / 2);
            lengths[i] = lists[i]->getLength();
        }

        for (int i = size - 1; i >= 0; i--)
            set->insert(lists[i]);
        delete [] lists;

        bool sameNumberOfElements = true;

        for (int i = 0; i < size && sameNumberOfElements; i++)
            if (set->at(i)->getLength() != lengths[i])
                sameNumberOfElements = false;

        QVERIFY(sameNumberOfElements);
    }

    void testElementsUnchanged()
    {
        const int size = 19;
        LinkedList **lists = new LinkedList*[size];

        for (int i = 0; i < size; i++)
        {
            lists[i] = new LinkedList();
            for (int j = 0; j < i * i; j++)
                lists[i]->insert(j);
        }

        for (int i = size - 1; i >= 0; i--)
            set->insert(lists[i]);

        for (int i = 0; i < size; i++)
            for (int j = 0; j < i * i; j++)
                lists[i]->remove(j);

        bool allAreEmpty = true;

        for (int i = 0; i < size && allAreEmpty; i++)
            if (lists[i]->getLength() != 0)
                allAreEmpty = false;

        delete [] lists;

        QVERIFY(allAreEmpty);
    }

private:
    SortedSet *set;
};
