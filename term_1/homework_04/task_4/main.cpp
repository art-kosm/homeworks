#include <iostream>
#include "transformToPostfix.h"
#include "computePostfix.h"

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

    return balance == 0;
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
        double result = computePostfix(output);
        cout << "Result is " << result << "\n";
    }
    else
        cout << "Your expression has some mistakes. " << "\n";

    return 0;
}
