#pragma once

#include "stack.h"

class LinkedListStack : public Stack
{
public:
    LinkedListStack();
    ~LinkedListStack();
    void push(int value);
    char pop();
    char peek() const;
    void print() const;
    bool isEmpty() const;

private:
    struct StackElement;
    StackElement *top;

    StackElement *createStackElement(int value, StackElement *next);
    void removeAfter(StackElement *current);
};
