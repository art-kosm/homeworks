#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "valueNotFoundException.h"

class ValueNotFoundExceptionTest : public QObject
{
    Q_OBJECT

public:
    explicit ValueNotFoundExceptionTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testCreateException()
    {
        ValueNotFoundException *exception = new ValueNotFoundException("Info");

        QVERIFY(exception->data() == "Info");
    }
};
