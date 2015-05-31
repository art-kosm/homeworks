#include "linkedList.h"

LinkedList::LinkedList()
{
    ListElement *guard = new ListElement;
    guard->value = QString();
    guard->next = nullptr;
    head = guard;
}

LinkedList::~LinkedList()
{
    ListElement *current = head;

    while (current->next != nullptr)
        deleteNextElement(current);

    delete head;
}

ListElement *LinkedList::find(const QString &value) const
{
    ListElement *current = head;
    while (current->next != nullptr && value != current->next->value)
        current = current->next;

    return current;
}

bool LinkedList::contains(const QString &value) const
{
    ListElement *element = find(value);

    return  element->next != nullptr &&
            value == element->next->value;
}

bool LinkedList::add(const QString &value)
{
    bool result = false;

    ListElement *current = head;
    while (current->next != nullptr)
    {
        if (current->next->value == value)
            result = true;
        current = current->next;
    }

    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->next = current->next;
    current->next = newElement;

    return result;
}

bool LinkedList::remove(const QString &value)
{
    bool result = false;

    ListElement *current = head;
    while (current != nullptr && current->next != nullptr)
    {
        if (current->next->value == value)
        {
            deleteNextElement(current);
            result = true;
        }
        else
            current = current->next;
    }

    return result;
}

QString LinkedList::at(int index) const
{
    ListElement *current = head; ///the list may be empty
    for (int i = 0; i < index + 1; i++) ///head->next has zero index
        if (current->next != nullptr)
            current = current->next;
        else
            return QString();

    return current->value;
}

int LinkedList::length() const
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

void LinkedList::deleteNextElement(ListElement *current)
{
    ListElement *element = current->next;
    current->next = current->next->next;

    delete element;
}
