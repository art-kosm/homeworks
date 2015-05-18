#include <cstdio>
#include "linkedList.h"
#include "doublyLinkedList.h"

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

    delete head;
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

bool DoublyLinkedList::isEmpty() const
{
    return head->next == nullptr;
}

int DoublyLinkedList::getLength() const
{
    int length = 0;

    for (ListElement *current = head->next; current!= nullptr; current = current->next)
        length++;

    return length;
}

bool DoublyLinkedList::contains(int value) const
{
    for (ListElement *current = head->next; current!= nullptr; current = current->next)
        if (current->value == value)
            return true;

    return false;
}

void DoublyLinkedList::print() const
{
    ListElement *current = head->next;

    while (current != nullptr)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}
