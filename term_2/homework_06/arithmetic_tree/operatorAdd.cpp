#include "operatorAdd.h"

OperatorAdd::OperatorAdd()
{
    value = '+';
}

int OperatorAdd::calculate(int left, int right) const
{
    return left + right;
}
