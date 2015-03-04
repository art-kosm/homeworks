#pragma once

class DoublyLinkedList : public LinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insert(int value);
    void remove(int value);
    void print();

private:
    struct ListElement;
    void removeAfter(ListElement *current);

private:
    ListElement *head;    
};
