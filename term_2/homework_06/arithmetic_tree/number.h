#pragma once

#include "operand.h"

class Number : public Operand
{
public:
    Number(int value);

    ///Functions inherited from the base class

    int calculate() const;
    void print() const;

private:
    int value = 0;
};
