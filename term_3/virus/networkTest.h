#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "network.h"

#include <iostream>

class UnprotectedComputer : public Computer
{
protected:
    bool tryToInfect(OperatingSystem system)
    {
        return true;
    }
};

class NetworkTest : public QObject
{
    Q_OBJECT

public:
    explicit NetworkTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        network = new Network;
    }

    void cleanup()
    {
        delete network;
    }

    void testInfected()
    {
        Computer computer(OperatingSystem(rand() % 5), true);

        QVERIFY(computer.isInfected());
    }

    void testNotInfected()
    {
        Computer computer(OperatingSystem(rand() % 5), false);

        QVERIFY(!computer.isInfected());
    }

    void testNotInstantlyInfected()
    {
        Computer computer(OperatingSystem(rand() % 5));
        network->addNewComputer(&computer);

        QVERIFY(!computer.isInfected());
    }

    void testNotInfectedAfterUpdating()
    {
        Computer computer1(OperatingSystem(rand() % 5), true);
        Computer computer2(NoSystem);
        network->addNewComputer(&computer1);
        network->addNewComputer(&computer2, {&computer1});
        network->update();

        QVERIFY(!computer2.isInfected());
    }

    void testInfectedAfterUpdating()
    {
        Computer computer1(OperatingSystem(rand() % 5), true);
        UnprotectedComputer computer2;
        network->addNewComputer(&computer1);
        network->addNewComputer(&computer2, {&computer1});
        network->update();

        QVERIFY(computer2.isInfected());
    }

    void testInfectedNeighbour()
    {
        Computer computer1(OperatingSystem(rand() % 5), true);
        UnprotectedComputer computer2;
        Computer computer3(NoSystem);
        network->addNewComputer(&computer1);
        network->addNewComputer(&computer2, {&computer1});
        network->addNewComputer(&computer3, {&computer1});
        network->update();

        QVERIFY(computer2.isInfected());
    }

    void testNotInfectedNeighbour()
    {
        Computer computer1(OperatingSystem(rand() % 5), true);
        UnprotectedComputer computer2;
        Computer computer3(NoSystem);
        network->addNewComputer(&computer1);
        network->addNewComputer(&computer2, {&computer1});
        network->addNewComputer(&computer3, {&computer1});
        network->update();

        QVERIFY(!computer3.isInfected());
    }

    void testTwoTurns()
    {
        Computer computer1(OperatingSystem(rand() % 5), true);
        UnprotectedComputer computer2;
        UnprotectedComputer computer3;
        network->addNewComputer(&computer1);
        network->addNewComputer(&computer2, {&computer1});
        network->addNewComputer(&computer3, {&computer2});
        network->update();
        network->update();

        QVERIFY(computer3.isInfected());
    }

    void testTwoPathsShortTime()
    {
        Computer computer1(OperatingSystem(rand() % 5), true);
        UnprotectedComputer computer2;
        UnprotectedComputer computer3;
        UnprotectedComputer computer4;
        Computer computer5(NoSystem);

        network->addNewComputer(&computer1);
        network->addNewComputer(&computer2, {&computer1});
        network->addNewComputer(&computer3, {&computer2});
        network->addNewComputer(&computer4, {&computer3});
        network->addNewComputer(&computer5, {&computer1, &computer4});
        network->update();
        network->update();

        QVERIFY(!computer4.isInfected());
    }

    void testTwoPathsLongTime()
    {
        Computer computer1(OperatingSystem(rand() % 5), true);
        UnprotectedComputer computer2;
        UnprotectedComputer computer3;
        UnprotectedComputer computer4;
        Computer computer5(NoSystem);

        network->addNewComputer(&computer1);
        network->addNewComputer(&computer2, {&computer1});
        network->addNewComputer(&computer3, {&computer2});
        network->addNewComputer(&computer4, {&computer3});
        network->addNewComputer(&computer5, {&computer1, &computer4});
        network->update();
        network->update();
        network->update();

        QVERIFY(computer4.isInfected());
    }

private:
    Network *network;
};
