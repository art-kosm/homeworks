#pragma once

#include "operator.h"

class OperatorAdd : public Operator
{
public:
    OperatorAdd();

    ///Functions inherited from the base class

    char get() const;
    void print() const;
};
