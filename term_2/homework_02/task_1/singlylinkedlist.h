#pragma once

#include "linkedList.h"

class SinglyLinkedList : public LinkedList
{
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    void insert(int value);
    void remove(int value);
    bool isEmpty() const;
    int getLength() const;
    bool contains(int value) const;
    void print() const;

private:
    struct ListElement;
    ListElement *head;

    void removeAfter(ListElement *current);
};
