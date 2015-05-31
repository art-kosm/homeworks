#include "uniqueList.h"

bool UniqueList::add(const QString &value) throw (ValueAlreadyExistsException)
{
    ListElement *element = find(value);

    if (element->next != nullptr)
        throw ValueAlreadyExistsException(value);
    else
    {
        ListElement *newElement = new ListElement;
        newElement->value = value;
        newElement->next = nullptr;
        element->next = newElement;
    }

    return true;
}

bool UniqueList::remove(const QString &value) throw (ValueNotFoundException)
{
    bool found = false;

    ListElement *current = head;
    while (current != nullptr && current->next != nullptr)
    {
        if (current->next->value == value)
        {
            deleteNextElement(current);
            found = true;
        }
        else
            current = current->next;
    }

    if (!found)
        throw ValueNotFoundException(value);

    return true;
}
