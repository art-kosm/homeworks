#pragma once

#include "operand.h"

class Number : public Operand
{
public:
    Number(int value);
    int calculate() const;
    void print() const;

private:
    int value = 0;
};
