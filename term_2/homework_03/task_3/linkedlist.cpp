#include <cstdio>
#include "linkedList.h"

struct LinkedList::ListElement
{
    int value;
    ListElement *next;
};

LinkedList::LinkedList()
{
    ListElement *guard = new ListElement;

    guard->value = 0;
    guard->next = nullptr;

    head = guard;
}

LinkedList::~LinkedList()
{
    ListElement *current = head;

    while (current->next != nullptr)
        removeAfter(current);

    delete head;
}

void LinkedList::insert(int value)
{
    ListElement *current = head;
    while (current->next != nullptr)
        current = current->next;

    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->next = current->next;
    current->next = newElement;
}

void LinkedList::removeAfter(ListElement *current)
{
    ListElement *element = current->next;
    current->next = current->next->next;

    delete element;
}

void LinkedList::remove(int value)
{
    ListElement *current = head;
    while (current->next != nullptr && current->next->value != value)
        current = current->next;

    if (current->next != nullptr)
        removeAfter(current);
}

void LinkedList::print() const
{
    ListElement *current = head->next;

    while (current != nullptr)
    {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

int LinkedList::getLength() const
{
    int length = 0;

    ListElement *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
        length++;
    }

    return length;
}
