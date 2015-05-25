#include <cstdio>
#include "singlyLinkedList.h"

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

    delete head;
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

bool SinglyLinkedList::isEmpty() const
{
    return head->next == nullptr;
}

int SinglyLinkedList::getLength() const
{
    int length = 0;

    for (ListElement *current = head->next; current!= nullptr; current = current->next)
        length++;

    return length;
}

bool SinglyLinkedList::contains(int value) const
{
    for (ListElement *current = head->next; current!= nullptr; current = current->next)
        if (current->value == value)
            return true;

    return false;
}

void SinglyLinkedList::print() const
{
    ListElement *current = head->next;

    while (current != nullptr)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}
