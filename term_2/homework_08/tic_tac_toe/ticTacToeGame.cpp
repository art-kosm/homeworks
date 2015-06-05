#include "ticTacToeGame.h"

TicTacToeGame::TicTacToeGame(int size, QObject *parent) :
    QObject(parent),

    sideLength(size),
    buttonsNumber(size * size),
    values(new FieldValue[buttonsNumber]),

    turnX(true),
    firstTurn(false),
    status(unfinished)
{
    for (int i = 0; i < buttonsNumber; i++)
        values[i] = empty;
}

TicTacToeGame::~TicTacToeGame()
{
    delete [] values;
}

GameStatus TicTacToeGame::getStatus()
{
    return status;
}

void TicTacToeGame::nextTurn(int buttonNumber)
{
    if (firstTurn)
    {
        emit newGame();
        firstTurn = false;
        status = unfinished;
    }

    if (values[buttonNumber] == empty)
    {
        values[buttonNumber] = turnX ? cross : nought;
        turnX = !turnX;
        emit turnMade(buttonNumber, values[buttonNumber]);

        checkForWinner();
    }
}

void TicTacToeGame::checkForWinner()
{
    if (    horizontalWinner() || verticalWinner() ||
            majorDiagonalWinner() || minorDiagonalWinner() ||
            isDraw())
    {
        emit gameFinished(status);

        turnX = true;
        firstTurn = true;
        for (int i = 0; i < buttonsNumber; i++)
            values[i] = empty;
    }
}

bool TicTacToeGame::horizontalWinner()
{
    bool sequence = false;

    for (int i = 0; i < buttonsNumber; i += sideLength)
    {
        for (int j = 0; j < sideLength - 1; j++)
        {
            sequence = values[i + j] != empty &&
                       values[i + j] == values[i + j + 1];
            if (!sequence)
            {
                status = unfinished;
                break;
            }
            setWinner(values[i + j]);
        }
        if (sequence)
            break;
    }

    return sequence;
}

bool TicTacToeGame::verticalWinner()
{
    bool sequence = false;
    for (int i = 0; i < sideLength; i++)
    {
        for (int j = 0; j < buttonsNumber - sideLength; j += sideLength)
        {
            sequence = values[i + j] != empty &&
                       values[i + j] == values[i + j + sideLength];
            if (!sequence)
            {
                status = unfinished;
                break;
            }
            setWinner(values[i + j]);
        }
        if (sequence)
            break;
    }

    return sequence;
}

bool TicTacToeGame::majorDiagonalWinner()
{
    bool sequence = false;
    for (int i = 0; i < buttonsNumber - 1; i += sideLength + 1)
    {
        sequence = values[i] != empty &&
                   values[i] == values[i + sideLength + 1];
        if (!sequence)
        {
            status = unfinished;
            break;
        }
        setWinner(values[i]);
    }

    return sequence;
}

bool TicTacToeGame::minorDiagonalWinner()
{
    bool sequence = false;
    for (int i = sideLength - 1; i < buttonsNumber - sideLength; i += sideLength - 1)
    {
        sequence = values[i] != empty &&
                   values[i] == values[i + sideLength - 1];
        if (!sequence)
        {
            status = unfinished;
            break;
        }
        setWinner(values[i]);
    }

    return sequence;
}

bool TicTacToeGame::isDraw()
{
    bool noEmptyPlaces = true;
    for (int i = 0; i < buttonsNumber && noEmptyPlaces; i++)
        if (values[i] == empty)
            noEmptyPlaces = false;

    if (noEmptyPlaces)
        status = draw;

    return noEmptyPlaces;
}

void TicTacToeGame::setWinner(FieldValue value)
{
    if (value == cross)
        status = crossesWon;
    else if (value == nought)
        status = noughtsWon;
}
