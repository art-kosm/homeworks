#include <iostream>
#include "computePostfix.h"

using namespace std;

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

    double result = computePostfix(input);
    cout << "Result is " << result << "\n";

    return 0;
}
