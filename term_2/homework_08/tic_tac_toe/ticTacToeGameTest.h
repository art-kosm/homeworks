#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "ticTacToeGame.h"

class TicTacToeGameTest : public QObject
{
    Q_OBJECT

public:
    explicit TicTacToeGameTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        game = new TicTacToeGame(3);
    }

    void cleanup()
    {
        delete game;
    }

    void testInitialWin()
    {
        QVERIFY(game->getStatus() == unfinished);
    }

    void testCrossesWin()
    {
        game->nextTurn(0);
        game->nextTurn(3);
        game->nextTurn(1);
        game->nextTurn(4);
        game->nextTurn(2);

        QVERIFY(game->getStatus() == crossesWon);
    }

    void testNoughtsWin()
    {
        game->nextTurn(0);
        game->nextTurn(3);
        game->nextTurn(1);
        game->nextTurn(4);
        game->nextTurn(8);
        game->nextTurn(5);

        QVERIFY(game->getStatus() == noughtsWon);
    }

    void testDraw()
    {
        game->nextTurn(0);
        game->nextTurn(1);
        game->nextTurn(2);
        game->nextTurn(4);
        game->nextTurn(3);
        game->nextTurn(5);
        game->nextTurn(8);
        game->nextTurn(6);
        game->nextTurn(7);

        QVERIFY(game->getStatus() == draw);
    }

    void testUnfinishedNewGame()
    {
        game->nextTurn(0);
        game->nextTurn(3);
        game->nextTurn(1);
        game->nextTurn(4);
        game->nextTurn(2);
        game->nextTurn(5);

        QVERIFY(game->getStatus() == unfinished);
    }

private:
    TicTacToeGame *game;
};
