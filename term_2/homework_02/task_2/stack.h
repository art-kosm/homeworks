#pragma once

class Stack
{
public:
    virtual ~Stack() {}
    virtual void push(int value) = 0;
    virtual char pop() = 0;
    virtual char peek() = 0;
    virtual void print() = 0;
    virtual bool isEmpty() = 0;
};
