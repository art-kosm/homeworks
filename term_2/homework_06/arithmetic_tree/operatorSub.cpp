#include "operatorSub.h"

OperatorSub::OperatorSub()
{
    value = '-';
}

int OperatorSub::calculate(int left, int right) const
{
    return left - right;
}
