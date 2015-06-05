#include "operatorDiv.h"

OperatorDiv::OperatorDiv()
{
    value = '/';
}

int OperatorDiv::calculate(int left, int right) const
{
    return left / right;
}
