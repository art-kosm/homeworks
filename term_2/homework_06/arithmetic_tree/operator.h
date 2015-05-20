#pragma once

class Operator
{
public:
    virtual ~Operator() {}
    char get() const;
    void print() const;

protected:
    char value;
};
