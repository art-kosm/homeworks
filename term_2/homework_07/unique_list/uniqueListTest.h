#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "uniqueList.h"

class UniqueListTest : public QObject
{
    Q_OBJECT

public:
    explicit UniqueListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        list = new UniqueList();
    }

    void cleanup()
    {
        delete list;
    }

    void testLengthEmpty()
    {
        QVERIFY(list->length() == 0);
    }

    void testLengthOneElement()
    {
        list->add("jaguar");

        QVERIFY(list->length() == 1);
    }

    void testLengthManyElements()
    {
        const int size = 100;
        for (int i = 0; i < size; i++)
            list->add(QString::number(i - 5));

        QVERIFY(list->length() == size);
    }

    void testLengthRemoveExisting()
    {
        list->add("cat");
        list->add("bear");
        list->add("tiger");
        list->remove("tiger");

        QVERIFY(list->length() == 2);
    }

    void testRemoveNotExisting()
    {
        bool caught = false;
        try
        {
            list->add("rabbit");
            list->remove("cow");
        }
        catch (const ValueNotFoundException &)
        {
            caught = true;
        }

        QVERIFY(caught);
    }

    void testRemoveNotExistingInfo()
    {
        QString data = "";
        try
        {
            list->add("marten");
            list->remove("rat");
        }
        catch (const ValueNotFoundException &exception)
        {
            data = exception.data();
        }

        QVERIFY(data == "rat");
    }

    void testInsertManyTimes()
    {
        bool caught = false;
        try
        {
            const int size = 32;
            for (int i = 0; i < size; i++)
                list->add("dog");
        }
        catch (const ValueAlreadyExistsException &)
        {
            caught = true;
        }

        QVERIFY(caught);
    }

    void testInsertManyTimesInfo()
    {
        QString data = "";
        try
        {
            list->add("weasel");
            list->add("weasel");
        }
        catch (const ValueAlreadyExistsException &exception)
        {
            data = exception.data();
        }

        QVERIFY(data == "weasel");
    }

    void testContainsOneElement()
    {
        list->add("goat");

        QVERIFY(list->contains("goat"));
    }

    void testContainsManyElements()
    {
        list->add("mouse");
        list->add("hamster");
        list->add("lion");

        QVERIFY(list->contains("hamster"));
    }

    void testContainsNonExisting()
    {
        list->add("panther");
        list->add("pony");
        list->add("horse");

        QVERIFY(!list->contains("lynx"));
    }

    void testContainsRemoveExisting()
    {
        list->add("cheetah");
        list->add("giraffe");
        list->add("serval");
        list->remove("giraffe");

        QVERIFY(!list->contains("giraffe"));
    }

    void testAtOneElement()
    {
        list->add("leopard");

        QVERIFY(list->at(0) == "leopard");
    }

    void testAtManyElements()
    {
        list->add("ocelot");
        list->add("gull");
        list->add("cock");

        QVERIFY(list->at(1) == "gull");
    }

    void testAtRemove()
    {
        list->add("dove");
        list->add("raven");
        list->add("cicada");
        list->remove("raven");

        QVERIFY(list->at(1) == "cicada");
    }

    void testLotsOfElementsLength()
    {
        const int size = 2357;
        for (int i = 0; i < size; i++)
            list->add(QString::number(2 * i) + " herrings");

        QVERIFY(list->length() == size);
    }

    void testLotsOfElementsContains()
    {
        const int size = 5813;
        for (int i = 0; i < size; i++)
            list->add(QString::number(3 * i) + " catfish");

        QVERIFY(list->contains("999 catfish"));
    }

    void testLotsOfElementsAt()
    {
        const int size = 10001;
        for (int i = 0; i < size; i++)
            list->add(QString::number(4 * i) + " glowworms");

        QVERIFY(list->at(10000) == "40000 glowworms");
    }

private:
    UniqueList *list;
};
