#include "uniqueList.h"

struct UniqueList::ListElement
{
    QString value;
    ListElement *next;
};

UniqueList::UniqueList()
{
    ListElement *guard = new ListElement;
    guard->value = QString();
    guard->next = nullptr;
    head = guard;
}

UniqueList::~UniqueList()
{
    ListElement *current = head;

    while (current->next != nullptr)
        deleteNextElement(current);

    delete head;
}

UniqueList::ListElement *UniqueList::find(const QString &value) const
{
    ListElement *current = head;
    while (current->next != nullptr && value != current->next->value)
        current = current->next;

    return current;
}

bool UniqueList::contains(const QString &value) const
{
    ListElement *element = find(value);

    return  element->next != nullptr &&
            value == element->next->value;
}

void UniqueList::add(const QString &value) throw (ValueAlreadyExistsException)
{
    ListElement *element = find(value);

    if (element->next != nullptr)   ///found
        throw ValueAlreadyExistsException(value);
    else                            ///not found
    {
        ListElement *newElement = new ListElement;
        newElement->value = value;
        newElement->next = nullptr;
        element->next = newElement;
    }
}

void UniqueList::remove(const QString &value) throw (ValueNotFoundException)
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
}

QString UniqueList::at(int index) const
{
    ListElement *current = head; //the list may be empty
    for (int i = 0; i < index + 1; i++) //head->next has zero index
        if (current->next != nullptr)
            current = current->next;
        else
            return QString();

    return current->value;
}

int UniqueList::length() const //number of useful elements
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

void UniqueList::deleteNextElement(ListElement *current)
{
    ListElement *element = current->next;
    current->next = current->next->next;

    delete element;
}
