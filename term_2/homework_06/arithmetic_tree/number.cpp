#include <iostream>
#include "number.h"

Number::Number(int value)
{
    this->value = value;
}

int Number::calculate() const
{
    return value;
}

void Number::print() const
{
    std::cout << value;
}
