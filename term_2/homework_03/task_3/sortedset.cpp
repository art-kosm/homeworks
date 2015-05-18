#include "sortedSet.h"
#include "listsComparator.h"

struct SortedSet::ListElement
{
    LinkedList *value;
    ListElement *next;
};

SortedSet::SortedSet()
{
    ListElement *guard = new ListElement;

    guard->value = nullptr;
    guard->next = nullptr;

    head = guard;
}

SortedSet::~SortedSet()
{
    ListElement *current = head;

    while (current->next != nullptr)
        removeAfter(current);

    delete head;
}

void SortedSet::insert(LinkedList *value)
{
    ListsComparator *comparator = new ListsComparator();

    ListElement *current = head;
    while (current->next != nullptr && !comparator->isGreaterThan(current->next->value, value))
        current = current->next;

    delete comparator;

    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->next = current->next;
    current->next = newElement;
}

void SortedSet::print() const
{
    ListElement *current = head->next;

    while (current != nullptr)
    {
        current->value->print();
        current = current->next;
    }
}

LinkedList *SortedSet::at(int index)
{
    ListElement *current = head;

    for (int i = 0; i < index + 1; i++)
        if (current->next != nullptr)
            current = current->next;
        else
            return nullptr;

    return current->value;
}

void SortedSet::removeAfter(ListElement *current)
{
    ListElement *element = current->next;
    current->next = current->next->next;

    delete element;
}
