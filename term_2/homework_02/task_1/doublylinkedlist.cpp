#include <cstdio>
#include "linkedlist.h"
#include "doublylinkedlist.h"

struct DoublyLinkedList::ListElement
{
    int value;
    ListElement *next;
    ListElement *previous;
};

DoublyLinkedList::DoublyLinkedList()
{
    ListElement *guard = new ListElement;

    guard->value = 0;
    guard->next = nullptr;
    guard->previous = nullptr;

    head = guard;
}

DoublyLinkedList::~DoublyLinkedList()
{
    ListElement *current = head;

    while (current->next != nullptr)
        removeAfter(current);
}

void DoublyLinkedList::insert(int value)
{
    ListElement *current = head;
    while (current->next != nullptr)
        current = current->next;

    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->next = current->next;
    current->next = newElement;
    newElement->previous = current;
}

void DoublyLinkedList::removeAfter(ListElement *current)
{
    ListElement *element = current->next;
    current->next = current->next->next;
    if (current->next != nullptr && current->next->next != nullptr)
        current->next->next->previous = current;
    delete element;
}

void DoublyLinkedList::remove(int value)
{
    ListElement *current = head;
    while (current->next != nullptr && current->next->value != value)
        current = current->next;

    if (current->next != nullptr)
        removeAfter(current);
}

void DoublyLinkedList::print()
{
    ListElement *current = head->next;

    while (current != nullptr)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}
