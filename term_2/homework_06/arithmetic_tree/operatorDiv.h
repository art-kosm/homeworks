#pragma once

#include "operator.h"

class OperatorDiv : public Operator
{
public:
    OperatorDiv();

    ///Functions inherited from the base class

    char get() const;
    void print() const;
};
