#include <cstdio>
#include "linkedlist.h"
#include "singlylinkedlist.h"

struct SinglyLinkedList::ListElement
{
    int value;
    ListElement *next;
};

SinglyLinkedList::SinglyLinkedList()
{
    ListElement *guard = new ListElement;

    guard->value = 0;
    guard->next = nullptr;

    head = guard;
}

SinglyLinkedList::~SinglyLinkedList()
{
    ListElement *current = head;

    while (current->next != nullptr)
        removeAfter(current);
}

void SinglyLinkedList::insert(int value)
{
    ListElement *current = head;
    while (current->next != nullptr)
        current = current->next;

    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->next = current->next;
    current->next = newElement;
}

void SinglyLinkedList::removeAfter(ListElement *current)
{
    ListElement *element = current->next;
    current->next = current->next->next;
    delete element;
}

void SinglyLinkedList::remove(int value)
{
    ListElement *current = head;
    while (current->next != nullptr && current->next->value != value)
        current = current->next;

    if (current->next != nullptr)
        removeAfter(current);
}

void SinglyLinkedList::print()
{
    ListElement *current = head->next;

    while (current != nullptr)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}
