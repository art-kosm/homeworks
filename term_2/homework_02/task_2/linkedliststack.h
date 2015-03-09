#pragma once

class LinkedListStack : public Stack
{
public:
    LinkedListStack();
    ~LinkedListStack();
    void push(int value);
    char pop();
    char peek();
    void print();
    bool isEmpty();

private:
    struct StackElement;
    StackElement *createStackElement(int value, StackElement *next);
    void removeAfter(StackElement *current);

    StackElement *top;
};