#pragma once

#include "stack.h"

class RecursiveStack : public Stack
{
public:
    RecursiveStack();
    ~RecursiveStack();
    void push(int value);
    char pop();
    char peek() const;
    void print() const;
    bool isEmpty() const;

private:
    char value;
    RecursiveStack *stack;
};
