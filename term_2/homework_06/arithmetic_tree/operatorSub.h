#pragma once

#include "operator.h"

class OperatorSub : public Operator
{
public:
    OperatorSub();

    ///Functions inherited from the base class

    char get() const;
    void print() const;
};
