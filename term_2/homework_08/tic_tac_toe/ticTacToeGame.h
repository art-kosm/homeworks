#pragma once

#include <QObject>
#include <QString>

enum GameStatus
{
    unfinished,
    crossesWon,
    noughtsWon,
    draw
};

enum FieldValue
{
    empty,
    cross,
    nought,
};

class TicTacToeGame : public QObject
{
    Q_OBJECT

public:
    TicTacToeGame(int size, QObject *parent = 0);
    ~TicTacToeGame();
    GameStatus getStatus();

signals:
    void newGame();
    void turnMade(int, FieldValue);
    void gameFinished(GameStatus);

public slots:
    void nextTurn(int);

private:
    int sideLength;
    int buttonsNumber;
    FieldValue *values;

    bool turnX;
    bool firstTurn; /// = is first turn after previous game
    GameStatus status;

    /**
     * @brief checkForWinner
     *
     * If the game has finished, updates the status, emits gameFinished
     * signal and reinitializes fields
     */

    void checkForWinner();

    bool horizontalWinner();
    bool verticalWinner();
    bool majorDiagonalWinner();
    bool minorDiagonalWinner();
    bool isDraw();

    /**
     * @brief setWinner
     *
     * Sets status crossesWon or noughtsWon, depending on value
     * Does nothing if the value is incorrect
     */

    void setWinner(FieldValue);
};
