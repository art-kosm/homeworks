#include <iostream>
#include "lexer.h"
#include "parser.h"

enum Token
{
    begin = 'b',
    number,
    leftBracket = '(',
    rightBracket = ')',
    secondaryOperator,
    tertiaryOperator,
    error,
    end = '\0'
};

Token getToken(char *expression, int &position)
{
    char c = expression[position];
    position++;

    switch (c)
    {
        case '\0':
        case '(':
        case ')':
            return Token(c);

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            if (parseNumber(expression, position))
                return number;

        case '*':
        case '/':
            return secondaryOperator;

        case '+':
        case '-':
            return tertiaryOperator;

        default:
            std::cout << "Error at " << position << " (bad token)\n";
            return error;
    }
}

bool parseExpression(char *expression);
bool productionBegin(char *expression, int &position, Token &currentToken);
bool productionNumber(char *expression, int &position, Token &currentToken);
bool productionPrimary(char *expression, int &position, Token &currentToken);
bool productionSecondary(char *expression, int &position, Token &currentToken);
bool productionTertiary(char *expression, int &position, Token &currentToken);

bool parseExpression(char *expression)
{
    int position = 0;
    Token currentToken = begin;

    bool result = productionBegin(expression, position, currentToken);
    if (result)
        if (currentToken != end)
            std::cout << "Error at " << position << " (redundant ')' found)\n";

    return result && currentToken == end;
}

bool productionBegin(char *expression, int &position, Token &currentToken)
{
    while (currentToken != end && currentToken != rightBracket)
    {
        currentToken = getToken(expression, position);

        switch (currentToken)
        {
            case number:
                return productionNumber(expression, position, currentToken);

            case leftBracket:
                if (productionPrimary(expression, position, currentToken))
                    break;
                else
                    return false;

            case tertiaryOperator:
                return productionTertiary(expression, position, currentToken);

            default:
                std::cout << "Error at " << position << " (bad token)\n";
                currentToken = error;
                return false;
        }
    }

    return true;
}

bool productionNumber(char *expression, int &position, Token &currentToken)
{
    currentToken = getToken(expression, position);

    switch (currentToken)
    {
        case secondaryOperator:
            return productionSecondary(expression, position, currentToken);

        case tertiaryOperator:
            return productionTertiary(expression, position, currentToken);

        case rightBracket:
        case end:
            return true;

        default:
            std::cout << "Error at " << position << " (operator expected)\n";
            currentToken = error;
            return false;
    }
}

bool productionPrimary(char *expression, int &position, Token &currentToken)
{
    productionBegin(expression, position, currentToken);

    if (currentToken != rightBracket)
    {
        if (currentToken != error)
            std::cout << "Error at " << position << " (')' expected)\n";
        currentToken = error;
        return false;
    }

    currentToken = getToken(expression, position);

    return true;
}

bool productionSecondary(char *expression, int &position, Token &currentToken)
{
    currentToken = getToken(expression, position);

    switch (currentToken)
    {
        case number:
            return productionNumber(expression, position, currentToken);

        case leftBracket:
            return productionPrimary(expression, position, currentToken);

        default:
            std::cout << "Error at " << position << " (bad token)\n";
            currentToken = error;
            return false;
    }
}

bool productionTertiary(char *expression, int &position, Token &currentToken)
{
    while (currentToken != end && currentToken != rightBracket)
    {
        currentToken = getToken(expression, position);

        switch (currentToken)
        {
            case number:
                return productionNumber(expression, position, currentToken);

            case leftBracket:
                if (productionPrimary(expression, position, currentToken))
                    break;
                else
                    return false;

            default:
                std::cout << "Error at " << position << " (bad token)\n";
                currentToken = error;
                return false;
        }
    }

    return true;
}
