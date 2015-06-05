#include <iostream>
#include "operator.h"

char Operator::get() const
{
    return value;
}

void Operator::print() const
{
    std::cout << get();
}
