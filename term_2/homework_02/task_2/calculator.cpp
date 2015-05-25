#include <cstdio>
#include "calculator.h"
#include "transformToPostfix.h"
#include "computePostfix.h"

Calculator::Calculator()
{
    input = getStringFromStandardInput();
}

Calculator::Calculator(char *expression)
{
    input = expression;
}

Calculator::~Calculator()
{
    delete [] input;
}

int Calculator::calculateExpression() const
{
    double result = 0;

    if (bracketsAreCorrect(input))
    {
        char *output = transformToPostfix(input);
        result = computePostfix(output);
        delete [] output;
    }

    return result;
}

char *Calculator::getStringFromStandardInput()
{
    int size = 10;
    int length = 0;
    char *string = new char[size];

    while (true)
    {
        scanf("%c", &string[length]);
        length++;
        if (string[length - 1] == '\n')
        {
            string[length - 1] = '\0';
            break;
        }
        if (length == size)
        {
            size = size * 3 / 2 + 1;
            string = extend(string, length, size);
        }
    }

    return string;
}

char *Calculator::extend(char *&array, int length, int maxLength)
{
    char *newArray = new char[maxLength];
    for (int i = 0; i < length; i++)
        newArray[i] = array[i];

    delete [] array;

    return newArray;
}

bool Calculator::bracketsAreCorrect(char *string) const
{
    int balance = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '(')
            balance++;
        else if (string[i] == ')')
            balance--;
        if (balance < 0)
            break;
    }

    return balance == 0;
}
