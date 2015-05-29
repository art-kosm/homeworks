#pragma once

#include <cstdlib>
#include <ctime>
#include <QtTest/QtTest>
#include "bag.h"

class BagTest : public QObject
{
    Q_OBJECT

public:
    explicit BagTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        bag = new Bag();
    }

    void cleanup()
    {
        delete bag;
    }

    void testManyElementsContains1()
    {
        srand(time(0));
        for (int i = 0; i < 100; i++)
            bag->add(rand());

        int value = rand();
        bag->add(value);

        for (int i = 0; i < 100; i++)
            bag->add(rand());

        QVERIFY(bag->contains(value));
    }

    void testEmpty()
    {
        srand(time(0));
        int value = rand();

        QVERIFY(!bag->contains(value));
    }

    void testOneElementContains()
    {
        int value = rand();
        bag->add(value);

        QVERIFY(bag->contains(value));
    }

    void testOneElementDoesNotContain()
    {
        int value = rand();
        bag->add(value);

        QVERIFY(!bag->contains(value - 1));
    }

    void testOneElementRemove()
    {
        int value = rand();
        bag->add(value);
        bag->remove(value);

        QVERIFY(!bag->contains(value));
    }

    void testOneElementTwiceContains()
    {
        int value = rand();
        bag->add(value);
        bag->add(value);

        QVERIFY(bag->contains(value));
    }

    void testOneElementTwiceRemoveContains()
    {
        int value = rand();
        bag->add(value);
        bag->add(value);
        bag->remove(value);

        QVERIFY(bag->contains(value));
    }

    void testOneElementTwiceRemoveDoesNotContain()
    {
        int value = rand();
        bag->add(value);
        bag->add(value);
        bag->remove(value);
        bag->remove(value);

        QVERIFY(!bag->contains(value));
    }

    void testManyElementsContains()
    {
        for (int i = 0; i < 100; i++)
            bag->add(rand());

        int value = rand();
        bag->add(value);

        for (int i = 0; i < 100; i++)
            bag->add(rand());

        QVERIFY(bag->contains(value));
    }

    void testManyElementsRemove()
    {
        int value = rand();
        bag->add(value);

        for (int i = 0; i < 100; i++)
            bag->add(value - i);

        bag->remove(value - 50);

        QVERIFY(!bag->contains(value - 50));
    }

    void testManyElementsManyTimesContains()
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                bag->add(i);

        QVERIFY(bag->contains(5));
    }

    void testManyElementsManyTimesRemoveContains()
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                bag->add(i);

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 5; j++)
                bag->remove(i);

        QVERIFY(bag->contains(5));
    }

    void testManyElementsManyTimesRemoveDoesNotContain()
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                bag->add(i);

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                bag->remove(i);

        QVERIFY(!bag->contains(5));
    }

private:
    Bag *bag;
};
