#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "stupidSorter.h"

class StupidSorterTest : public QObject
{
    Q_OBJECT

public:
    explicit StupidSorterTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        sorter = new StupidSorter();
    }

    void cleanup()
    {
        delete sorter;
    }

    void testSorted()
    {
        const int size = 4;
        int array[size] = {0, 1, 99, 100};
        sorter->sort(array, size);
        QVERIFY(array[0] < array[1] &&
                array[1] < array[2] &&
                array[2] < array[3]);
    }

    void testUnsorted()
    {
        const int size = 4;
        int array[size] = {99, 0, 100, 1};
        sorter->sort(array, size);
        QVERIFY(array[0] < array[1] &&
                array[1] < array[2] &&
                array[2] < array[3]);
    }

private:
    StupidSorter *sorter;
};
