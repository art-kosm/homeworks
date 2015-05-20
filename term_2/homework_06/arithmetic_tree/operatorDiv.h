#pragma once

#include "operator.h"

class OperatorDiv : public Operator
{
public:
    OperatorDiv();
    char get() const;
    void print() const;
};
