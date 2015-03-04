#pragma once

class LinkedList
{
public:
    virtual ~LinkedList() {}
    virtual void insert(int value) = 0;
    virtual void remove(int value) = 0;
    virtual void print() = 0;
};
