#pragma once

class LinkedList
{
public:
    virtual ~LinkedList() {}
    virtual void insert(int value) = 0;
    virtual void remove(int value) = 0;
    virtual bool isEmpty() const = 0;
    virtual int getLength() const = 0;
    virtual bool contains(int value) const = 0;
    virtual void print() const = 0;
};
