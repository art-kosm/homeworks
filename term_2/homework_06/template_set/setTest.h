#pragma once

#include <cstdlib>
#include <ctime>
#include <QObject>
#include <QtTest/QtTest>
#include "set.h"

class SetTest : public QObject
{
    Q_OBJECT

public:
    explicit SetTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testBoolEmpty()
    {
        Set<bool> *set = new Set<bool>;

        QVERIFY(!set->contains(true) && !set->contains(false));

        delete set;
    }

    void testBoolOneElementContains()
    {
        Set<bool> *set = new Set<bool>;
        set->add(true);

        QVERIFY(set->contains(true));

        delete set;
    }

    void testBoolOneElementDoesNotContain()
    {
        Set<bool> *set = new Set<bool>;
        set->add(true);

        QVERIFY(!set->contains(false));

        delete set;
    }

    void testBoolManyElements()
    {
        Set<bool> *set = new Set<bool>;
        set->add(true);
        set->add(false);

        QVERIFY(set->contains(true) && set->contains(false));

        delete set;
    }

    void testBoolRemoveDoesNotContain()
    {
        Set<bool> *set = new Set<bool>;
        set->add(true);
        set->add(false);
        set->remove(true);

        QVERIFY(!set->contains(true));

        delete set;
    }

    void testBoolRemoveContains()
    {
        Set<bool> *set = new Set<bool>;
        set->add(true);
        set->add(false);
        set->remove(true);

        QVERIFY(set->contains(false));

        delete set;
    }

    void testBoolOneElementManyTimesRemove()
    {
        Set<bool> *set = new Set<bool>;
        for (int i = 0; i < 32768; i++)
            set->add(true);

        set->remove(true);

        QVERIFY(!set->contains(true));

        delete set;
    }

    void testBoolIntersect()
    {
        Set<bool> *set1 = new Set<bool>;
        set1->add(true);
        set1->add(false);
        Set<bool> *set2 = new Set<bool>;
        set2->add(false);

        Set<bool> *set = Set<bool>::intersect(set1, set2);

        delete set1;
        delete set2;

        QVERIFY(!set->contains(true) && set->contains(false));

        delete set;
    }

    void testBoolUnite()
    {
        Set<bool> *set1 = new Set<bool>;
        set1->add(true);
        Set<bool> *set2 = new Set<bool>;
        set2->add(false);

        Set<bool> *set = Set<bool>::unite(set1, set2);

        delete set1;
        delete set2;

        QVERIFY(set->contains(true) && set->contains(false));

        delete set;
    }

    void testIntEmpty()
    {
        srand(time(0));
        int value = rand();

        Set<int> *set = new Set<int>;

        QVERIFY(!set->contains(value));

        delete set;
    }

    void testIntOneElementContains()
    {
        int value = rand();

        Set<int> *set = new Set<int>;
        set->add(value);

        QVERIFY(set->contains(value));

        delete set;
    }

    void testIntOneElementDoesNotContain()
    {
        int value = rand();

        Set<int> *set = new Set<int>;
        set->add(value);

        QVERIFY(!set->contains(value - 1));

        delete set;
    }

    void testIntManyElementsContainsMiddle()
    {
        int value1 = rand();
        int value2 = value1 - 1;
        int value3 = value1 + 1;

        Set<int> *set = new Set<int>;
        set->add(value1);
        set->add(value2);
        set->add(value3);

        QVERIFY(set->contains(value2));

        delete set;
    }

    void testIntManyElementsContainsAll()
    {
        int value1 = rand();
        int value2 = value1 - 1;
        int value3 = value1 + 1;

        Set<int> *set = new Set<int>;
        set->add(value1);
        set->add(value2);
        set->add(value3);

        QVERIFY(set->contains(value1) && set->contains(value2) && set->contains(value3));

        delete set;
    }

    void testIntRemoveDoesNotContain()
    {
        int value1 = rand();
        int value2 = value1 - 1;
        int value3 = value1 + 1;

        Set<int> *set = new Set<int>;
        set->add(value1);
        set->add(value2);
        set->add(value3);
        set->remove(value2);

        QVERIFY(!set->contains(value2));

        delete set;
    }

    void testIntRemoveContains()
    {
        int value1 = rand();
        int value2 = value1 - 1;
        int value3 = value1 + 1;

        Set<int> *set = new Set<int>;
        set->add(value1);
        set->add(value2);
        set->add(value3);
        set->remove(value2);

        QVERIFY(set->contains(value1) && set->contains(value3));

        delete set;
    }

    void testIntOneElementManyTimesRemove()
    {
        Set<int> *set = new Set<int>;
        for (int i = 0; i < 65536; i++)
            set->add(16);

        set->remove(16);

        QVERIFY(!set->contains(16));
    }

    void testIntIntersect()
    {
        int value1 = rand();
        int value2 = value1 - 1;
        int value3 = value1 + 1;

        Set<int> *set1 = new Set<int>;
        set1->add(value1);
        set1->add(value2);
        Set<int> *set2 = new Set<int>;
        set2->add(value2);
        set2->add(value3);

        Set<int> *set = Set<int>::intersect(set1, set2);

        delete set1;
        delete set2;

        QVERIFY(!set->contains(value1) && set->contains(value2) && !set->contains(value3));

        delete set;
    }

    void testIntUnite()
    {
        int value1 = rand();
        int value2 = value1 - 1;

        Set<int> *set1 = new Set<int>;
        set1->add(value1);
        Set<int> *set2 = new Set<int>;
        set2->add(value2);

        Set<int> *set = Set<int>::unite(set1, set2);

        delete set1;
        delete set2;

        QVERIFY(set->contains(value1) && set->contains(value2));

        delete set;
    }
};
