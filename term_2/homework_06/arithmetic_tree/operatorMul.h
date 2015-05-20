#pragma once

#include "operator.h"

class OperatorMul : public Operator
{
public:
    OperatorMul();
    char get() const;
    void print() const;
};
