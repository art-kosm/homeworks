#pragma once

class RecursiveStack : public Stack
{
public:
    RecursiveStack();
    ~RecursiveStack();
    void push(int value);
    char pop();
    char peek();
    void print();
    bool isEmpty();

private:
    char value;
    RecursiveStack *stack;
};
