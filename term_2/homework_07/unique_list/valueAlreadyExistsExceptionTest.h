#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "valueAlreadyExistsException.h"

class ValueAlreadyExistsExceptionTest : public QObject
{
    Q_OBJECT

public:
    explicit ValueAlreadyExistsExceptionTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testCreateException()
    {
        ValueAlreadyExistsException *exception = new ValueAlreadyExistsException("Info");

        QVERIFY(exception->data() == "Info");
    }
};
