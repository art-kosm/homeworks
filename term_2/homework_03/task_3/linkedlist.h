#pragma once

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void insert(int value);
    void remove(int value);
    void print() const;
    int getLength() const;

protected:
    struct ListElement;
    ListElement *head;
    void removeAfter(ListElement *current);
};
