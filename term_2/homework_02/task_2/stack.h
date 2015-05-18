#pragma once

class Stack
{
public:
    virtual ~Stack() {}
    virtual void push(int value) = 0;
    virtual char pop() = 0;
    virtual char peek() const = 0;
    virtual void print() const = 0;
    virtual bool isEmpty() const = 0;
};
