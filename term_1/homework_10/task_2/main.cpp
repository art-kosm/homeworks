#include <iostream>
#include "parser.h"

char *extend(char *&array, int length, int maxLength)
{
    char *newArray = new char[maxLength];
    for (int i = 0; i < length; i++)
        newArray[i] = array[i];
    delete [] array;

    return newArray;
}

char *getStringFromStandardInput()
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

int main()
{
    std::cout << "Enter an expression: ";
    char *expression = getStringFromStandardInput();

    if (parseExpression(expression))
        std::cout << "Expression is correct\n";
    else
        std::cout << "Incorrect expression\n";

    delete [] expression;

    return 0;
}
