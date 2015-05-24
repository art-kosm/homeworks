#include "calculator.h"

double Calculator::calculate(int firstArgument, int secondArgument, const QString &operation) const
{
    switch (operation.at(0).cell())
    {
        case '+':
            return (double) firstArgument + secondArgument;

        case '-':
            return (double) firstArgument - secondArgument;

        case '*':
            return (double) firstArgument * secondArgument;

        case '/':
            return (double) firstArgument / secondArgument;

        case '^':
            return exponentiate(firstArgument, secondArgument);

        default:
            return -1;
    }
}

double Calculator::exponentiate(int base, int power) const
{
    if (power == 0)
        return 1;

    int binaryPower[65536];
    int length = 0;

    while (power > 0)
    {
        binaryPower[length] = power % 2;
        power /= 2;
        length++;
    }

    double result = base;

    for (int i = 1; i < length; i++)
    {
        result *= result;
        if (binaryPower[length - i - 1] == 1)
            result *= base;
    }

    return result;
}
