#pragma once

#include "operator.h"

class OperatorSub : public Operator
{
public:
    OperatorSub();
    char get() const;
    void print() const;
};
