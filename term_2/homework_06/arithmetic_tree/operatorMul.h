#pragma once

#include "operator.h"

class OperatorMul : public Operator
{
public:
    OperatorMul();

    ///Functions inherited from the base class

    char get() const;
    void print() const;
};
