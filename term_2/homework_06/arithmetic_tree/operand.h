#pragma once

class Operand
{
public:
    virtual ~Operand() {}
    virtual int calculate() const = 0;
    virtual void print() const = 0;
};
