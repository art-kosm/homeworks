#include <iostream>
#include "transformToPostfix.h"

using namespace std;

bool bracketsAreCorrect(char string[])
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

    if (balance != 0) return false; return true;
}

void printString(char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
        cout << string[i];
    cout << "\n";
}

void getInput(char input[])
{
    int counter = 0;
    char character;
    while ((character = getchar()) != '\n')
    {
        input[counter] = character;
        counter++;
    }
    input[counter] = '\0';
}

int main()
{
    const int size = 128;

    char input[size];
    cout << "Enter an expression: ";
    getInput(input);

    char output[size];

    if (bracketsAreCorrect(input))
    {
        transformToPostfix(input, output);
        printString(output);
    }
    else
        cout << "Your expression has some mistakes. " << "\n";

    return 0;
}
