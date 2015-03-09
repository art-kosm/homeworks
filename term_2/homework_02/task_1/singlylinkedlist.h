#pragma once

class SinglyLinkedList : public LinkedList
{
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    void insert(int value);
    void remove(int value);
    void print();

private:
    struct ListElement;
    void removeAfter(ListElement *current);

    ListElement *head;
};