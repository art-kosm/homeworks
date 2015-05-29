#pragma once

#include <cstdlib>
#include <ctime>
#include <QtTest/QtTest>
#include "vector.h"

class VectorTest : public QObject
{
    Q_OBJECT

public:
    explicit VectorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testNull()
    {
        Vector<int> *vector = new Vector<int>();

        QVERIFY(vector->isNull());
        delete vector;
    }

    void testOneDimensionNull()
    {
        dimensions = 1;
        int array[dimensions] = {0};
        Vector<int> *vector = new Vector<int>(dimensions, array);

        QVERIFY(vector->isNull());
        delete vector;
    }

    void testOneDimensionNotNull()
    {
        srand(time(0));
        dimensions = 1;
        int array[dimensions] = {rand()};
        Vector<int> *vector = new Vector<int>(dimensions, array);

        QVERIFY(!vector->isNull());
        delete vector;
    }

    void testOneDimensionLength()
    {
        dimensions = 1;
        int array[dimensions] = {rand()};
        Vector<int> *vector = new Vector<int>(dimensions, array);

        QVERIFY(vector->length() == dimensions);
        delete vector;
    }

    void testOneDimensionContents()
    {
        dimensions = 1;
        int value = rand();
        int array[dimensions] = {value};

        Vector<int> *vector = new Vector<int>(dimensions, array);
        int *values = vector->contents();

        QVERIFY(values[0] == value);
        delete vector;
        delete [] values;
    }

    void testOneDimensionShortAddition()
    {
        dimensions = 1;
        int value1 = rand();
        int value2 = rand();

        int array1[dimensions] = {value1};
        int array2[dimensions] = {value2};

        Vector<int> *vector1 = new Vector<int>(dimensions, array1);
        Vector<int> *vector2 = new Vector<int>(dimensions, array2);

        *vector1 += *vector2;
        int *values = vector1->contents();

        QVERIFY(values[0] == value1 + value2);
        delete vector1;
        delete vector2;
        delete [] values;
    }

    void testOneDimensionAddition()
    {
        dimensions = 1;
        int value1 = rand();
        int value2 = rand();

        int array1[dimensions] = {value1};
        int array2[dimensions] = {value2};

        Vector<int> *vector1 = new Vector<int>(dimensions, array1);
        Vector<int> *vector2 = new Vector<int>(dimensions, array2);

        Vector<int> vector = *vector1 + *vector2;
        int *values = vector.contents();

        QVERIFY(values[0] == value1 + value2);
        delete vector1;
        delete vector2;
        delete [] values;
    }

    void testOneDimensionShortSubtraction()
    {
        dimensions = 1;
        int value1 = rand();
        int value2 = rand();

        int array1[dimensions] = {value1};
        int array2[dimensions] = {value2};

        Vector<int> *vector1 = new Vector<int>(dimensions, array1);
        Vector<int> *vector2 = new Vector<int>(dimensions, array2);

        *vector1 -= *vector2;
        int *values = vector1->contents();

        QVERIFY(values[0] == value1 - value2);
        delete vector1;
        delete vector2;
        delete [] values;
    }

    void testOneDimensionSubtraction()
    {
        dimensions = 1;
        int value1 = rand();
        int value2 = rand();

        int array1[dimensions] = {value1};
        int array2[dimensions] = {value2};

        Vector<int> *vector1 = new Vector<int>(dimensions, array1);
        Vector<int> *vector2 = new Vector<int>(dimensions, array2);

        Vector<int> vector = *vector1 - *vector2;
        int *values = vector.contents();

        QVERIFY(values[0] == value1 - value2);
        delete vector1;
        delete vector2;
        delete [] values;
    }

    void testOneDimensionMultiplication()
    {
        dimensions = 1;
        int value1 = rand();
        int value2 = rand();

        int array1[dimensions] = {value1};
        int array2[dimensions] = {value2};

        Vector<int> *vector1 = new Vector<int>(dimensions, array1);
        Vector<int> *vector2 = new Vector<int>(dimensions, array2);
        int result = *vector1 * *vector2;

        QVERIFY(result == value1 * value2);
        delete vector1;
        delete vector2;
    }

    void testManyDimensionsNull()
    {
        dimensions = rand() % 99 + 2;
        int array[dimensions] = {0};
        Vector<int> *vector = new Vector<int>(dimensions, array);

        QVERIFY(vector->isNull());
        delete vector;
    }

    void testManyDimensionsNotNull()
    {
        dimensions = rand() % 99 + 2;
        int array[dimensions] = {rand()};
        Vector<int> *vector = new Vector<int>(dimensions, array);

        QVERIFY(!vector->isNull());
        delete vector;
    }

    void testManyDimensionsLength()
    {
        dimensions = rand() % 99 + 2;
        int array[dimensions] = {rand()};
        Vector<int> *vector = new Vector<int>(dimensions, array);

        QVERIFY(vector->length() == dimensions);
        delete vector;
    }

    void testManyDimensionsContents()
    {
        dimensions = rand() % 99 + 2;
        int value = rand();
        int array[dimensions] = {0};
        array[dimensions / 2] = value;

        Vector<int> *vector = new Vector<int>(dimensions, array);
        int *values = vector->contents();

        QVERIFY(values[dimensions / 2] == value);
        delete vector;
        delete [] values;
    }

    void testManyDimensionsShortAddition()
    {
        dimensions = rand() % 99 + 2;
        int value1 = rand();
        int value2 = rand();

        int array1[dimensions] = {0};
        array1[dimensions / 2] = value1;
        int array2[dimensions] = {0};
        array2[dimensions / 2] = value2;

        Vector<int> *vector1 = new Vector<int>(dimensions, array1);
        Vector<int> *vector2 = new Vector<int>(dimensions, array2);

        *vector1 += *vector2;
        int *values = vector1->contents();

        QVERIFY(values[dimensions / 2] == value1 + value2);
        delete vector1;
        delete vector2;
        delete [] values;
    }

    void testManyDimensionsAddition()
    {
        dimensions = rand() % 99 + 2;
        int value1 = rand();
        int value2 = rand();

        int array1[dimensions] = {0};
        array1[dimensions / 2] = value1;
        int array2[dimensions] = {0};
        array2[dimensions / 2] = value2;

        Vector<int> *vector1 = new Vector<int>(dimensions, array1);
        Vector<int> *vector2 = new Vector<int>(dimensions, array2);

        Vector<int> vector = *vector1 + *vector2;
        int *values = vector.contents();

        QVERIFY(values[dimensions / 2] == value1 + value2);
        delete vector1;
        delete vector2;
        delete [] values;
    }

    void testManyDimensionsShortSubtraction()
    {
        dimensions = rand() % 99 + 2;
        int value1 = rand();
        int value2 = rand();

        int array1[dimensions] = {0};
        array1[dimensions / 2] = value1;
        int array2[dimensions] = {0};
        array2[dimensions / 2] = value2;

        Vector<int> *vector1 = new Vector<int>(dimensions, array1);
        Vector<int> *vector2 = new Vector<int>(dimensions, array2);

        *vector1 -= *vector2;
        int *values = vector1->contents();

        QVERIFY(values[dimensions / 2] == value1 - value2);
        delete vector1;
        delete vector2;
        delete [] values;
    }

    void testManyDimensionsSubtraction()
    {
        dimensions = rand() % 99 + 2;
        int value1 = rand();
        int value2 = rand();

        int array1[dimensions] = {0};
        array1[dimensions / 2] = value1;
        int array2[dimensions] = {0};
        array2[dimensions / 2] = value2;

        Vector<int> *vector1 = new Vector<int>(dimensions, array1);
        Vector<int> *vector2 = new Vector<int>(dimensions, array2);

        Vector<int> vector = *vector1 - *vector2;
        int *values = vector.contents();

        QVERIFY(values[dimensions / 2] == value1 - value2);
        delete vector1;
        delete vector2;
        delete [] values;
    }

    void testManyDimensionsMultiplication()
    {
        dimensions = rand() % 99 + 2;
        int value1 = rand();
        int value2 = rand();
        int value3 = rand();
        int value4 = rand();

        int array1[dimensions] = {0};
        array1[dimensions / 2] = value1;
        array1[dimensions / 4] = value3;
        int array2[dimensions] = {0};
        array2[dimensions / 2] = value2;
        array2[dimensions / 4] = value4;

        Vector<int> *vector1 = new Vector<int>(dimensions, array1);
        Vector<int> *vector2 = new Vector<int>(dimensions, array2);
        int result = *vector1 * *vector2;

        QVERIFY(result == value1 * value2 + value3 * value4);
        delete vector1;
        delete vector2;
    }

    void testCopyConstructor()
    {
        dimensions = rand() % 99 + 2;
        int array[dimensions];
        for (int i = 0; i < dimensions; i++)
            array[i] = rand();

        Vector<int> *vector1 = new Vector<int>(dimensions, array);
        Vector<int> *vector2 = new Vector<int>(*vector1);
        *vector1 -= *vector2;

        QVERIFY(vector1->isNull());
        delete vector1;
        delete vector2;
    }

private:
    int dimensions;
};
