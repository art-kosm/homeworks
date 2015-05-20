#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "hashtable.h"

class HashtableTest : public QObject
{
    Q_OBJECT

public:
    explicit HashtableTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        hashtable = new Hashtable();
    }

    void cleanup()
    {
        delete hashtable;
    }

    void testEmptyElementsNumber()
    {
        QVERIFY(hashtable->getElementsNumber() == 0);
    }

    void testEmptyLoadFactor()
    {
        QVERIFY(hashtable->loadFactor() == 0);
    }

    void testEmptyConflicts()
    {
        QVERIFY(hashtable->conflicts() == 0);
    }

    void testEmptyMaxListLength()
    {
        QVERIFY(hashtable->maxListLength() == 0);
    }

    void testEmptyContains()
    {
        QVERIFY(!hashtable->contains("snail"));
    }

    void testNonEmptyElementsNumber()
    {
        hashtable->add("crow");
        hashtable->add("thrush");
        hashtable->add("crow");
        hashtable->add("owl");

        QVERIFY(hashtable->getElementsNumber() == 3);
    }

    void testNonEmptyLoadFactor()
    {
        hashtable->add("crow");
        hashtable->add("thrush");
        hashtable->add("crow");
        hashtable->add("owl");

        QVERIFY(hashtable->loadFactor() != 0);
    }

    void testContainsOneElement()
    {
        hashtable->add("goat");

        QVERIFY(hashtable->contains("goat"));
    }

    void testContainsManyElements()
    {
        hashtable->add("mouse");
        hashtable->add("hamster");
        hashtable->add("lion");

        QVERIFY(hashtable->contains("hamster"));
    }

    void testContainsNonExisting()
    {
        hashtable->add("panther");
        hashtable->add("pony");
        hashtable->add("horse");

        QVERIFY(!hashtable->contains("lynx"));
    }

    void testContainsRemoveExisting()
    {
        hashtable->add("cheetah");
        hashtable->add("giraffe");
        hashtable->add("serval");
        hashtable->remove("giraffe");

        QVERIFY(!hashtable->contains("giraffe"));
    }

    void testContainsRemoveNotExisting()
    {
        hashtable->add("elephant");
        hashtable->remove("panda");

        QVERIFY(hashtable->contains("elephant"));
    }

    void testLotsOfElementsElementsNumber()
    {
        const int size = 32768;
        for (int i = 0; i < size; i++)
            hashtable->add(QString::number(i * i) + " chimps");

        QVERIFY(hashtable->getElementsNumber() == size);
    }

    void testLotsOfElementsLoadFactor()
    {
        const int size = 65535;
        for (int i = 0; i < size; i++)
            hashtable->add(QString::number(i * i) + " gorillas");

        QVERIFY(hashtable->loadFactor() != 0);
    }

    void testLotsOfElementsContains()
    {
        const int size = 131313;
        for (int i = 0; i < size; i++)
            hashtable->add(QString::number(i * i) + " orangs");

        QVERIFY(hashtable->contains("65536 orangs"));
    }

    void testNewHashElementsNumber()
    {
        hashtable->setHashFunction(constantHash);
        hashtable->add("lemur");
        hashtable->add("lory");
        hashtable->add("toque");
        hashtable->add("lory");

        QVERIFY(hashtable->getElementsNumber() == 3);
    }

    void testNewHashLoadFactor()
    {
        hashtable->setHashFunction(constantHash);
        hashtable->add("marmoset");
        hashtable->add("carp");
        hashtable->add("shrimp");

        QVERIFY(hashtable->loadFactor() != 0);
    }

    void testNewHashContains()
    {
        hashtable->setHashFunction(constantHash);
        hashtable->add("octopus");
        hashtable->add("squid");
        hashtable->add("duck");

        QVERIFY(hashtable->contains("squid"));
    }

    void testNonEmptyConflicts()
    {
        hashtable->setHashFunction(constantHash);
        hashtable->add("pig");
        hashtable->add("goldfish");
        hashtable->add("platypus");

        QVERIFY(hashtable->conflicts() == 1);
    }

    void testNonEmptyMaxListLength()
    {
        hashtable->setHashFunction(constantHash);
        hashtable->add("angelfish");
        hashtable->add("clownfish");
        hashtable->add("crab");

        QVERIFY(hashtable->maxListLength() == 3);
    }

private:
    Hashtable *hashtable;

    static unsigned int constantHash(const QString &value, int modulo)
    {
        return 42 % modulo;
    }
};
