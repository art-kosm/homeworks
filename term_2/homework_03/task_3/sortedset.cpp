#include "sortedset.h"

/**
 * @brief ListElement struct
 *
 * Almost identical to LinkedList' one, contains a linked list instead of integer
 */
struct SortedSet::ListElement
{
    LinkedList *value;
    ListElement *next;
};

/**
 * @brief SortedSet constructor
 *
 * Almost identical to LinkedList' one
 */
SortedSet::SortedSet()
{
    ListElement *guard = new ListElement;

    guard->value = nullptr;
    guard->next = nullptr;

    head = guard;
}

/**
 * @brief SortedSet insert function
 *
 * Inserts the list, saving the set sorted
 *
 * @param value The list to be inserted
 */
void SortedSet::insert(LinkedList *value)
{
    ListElement *current = head;
    while (current->next != nullptr && !isGreaterThan(current->next->value, value))
        current = current->next;

    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->next = current->next;
    current->next = newElement;
}

/**
 * @brief SortedSet printer
 *
 * Displays the set on the console, printing it list by list
 */
void SortedSet::print() const
{
    ListElement *current = head->next;

    while (current != nullptr)
    {
        current->value->print();
        current = current->next;
    }
}
