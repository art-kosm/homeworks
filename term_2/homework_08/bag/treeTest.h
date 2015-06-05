#pragma once

#include <cstdlib>
#include <ctime>
#include <QtTest/QtTest>
#include "tree.h"

class TreeTest : public QObject
{
    Q_OBJECT

public:
    explicit TreeTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        tree = new Tree();
    }

    void cleanup()
    {
        delete tree;
    }

    void testEmpty()
    {
        srand(time(0));
        int value = rand();

        QVERIFY(!tree->contains(value));
    }

    void testOneElementContains()
    {
        int value = rand();
        tree->add(value);

        QVERIFY(tree->contains(value));
    }

    void testOneElementDoesNotContain()
    {
        int value = rand();
        tree->add(value);

        QVERIFY(!tree->contains(value - 1));
    }

    void testOneElementRemove()
    {
        int value = rand();
        tree->add(value);
        tree->remove(value);

        QVERIFY(!tree->contains(value));
    }

    void testOneElementTwiceContains()
    {
        int value = rand();
        tree->add(value);
        tree->add(value);

        QVERIFY(tree->contains(value));
    }

    void testOneElementTwiceRemoveContains()
    {
        int value = rand();
        tree->add(value);
        tree->add(value);
        tree->remove(value);

        QVERIFY(tree->contains(value));
    }

    void testOneElementTwiceRemoveDoesNotContain()
    {
        int value = rand();
        tree->add(value);
        tree->add(value);
        tree->remove(value);
        tree->remove(value);

        QVERIFY(!tree->contains(value));
    }

    void testManyElementsContains()
    {
        for (int i = 0; i < 100; i++)
            tree->add(rand());

        int value = rand();
        tree->add(value);

        for (int i = 0; i < 100; i++)
            tree->add(rand());

        QVERIFY(tree->contains(value));
    }

    void testManyElementsRemove()
    {
        int value = rand();
        tree->add(value);

        for (int i = 0; i < 100; i++)
            tree->add(value - i);

        tree->remove(value - 50);

        QVERIFY(!tree->contains(value - 50));
    }

    void testManyElementsManyTimesContains()
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                tree->add(i);

        QVERIFY(tree->contains(5));
    }

    void testManyElementsManyTimesRemoveContains()
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                tree->add(i);

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 5; j++)
                tree->remove(i);

        QVERIFY(tree->contains(5));
    }

    void testManyElementsManyTimesRemoveDoesNotContain()
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                tree->add(i);

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                tree->remove(i);

        QVERIFY(!tree->contains(5));
    }

private:
    Tree *tree;
};
