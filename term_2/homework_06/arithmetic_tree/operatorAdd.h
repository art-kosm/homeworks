#pragma once

#include "operator.h"

class OperatorAdd : public Operator
{
public:
    OperatorAdd();
    char get() const;
    void print() const;
};
