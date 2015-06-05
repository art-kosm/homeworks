#include "operatorMul.h"

OperatorMul::OperatorMul()
{
    value = '*';
}

int OperatorMul::calculate(int left, int right) const
{
    return left * right;
}
