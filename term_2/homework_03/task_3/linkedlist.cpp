#include <cstdio>
#include "linkedlist.h"

/**
 * @brief ListElement struct
 */
struct LinkedList::ListElement
{
    int value;
    ListElement *next;
};

/**
 * @brief LinkedList constructor
 *
 * Creates the guard element to make processing easier
 */
LinkedList::LinkedList()
{
    ListElement *guard = new ListElement;

    guard->value = 0;
    guard->next = nullptr;

    head = guard;
}

/**
 * @brief LinkedList destructor
 */
LinkedList::~LinkedList()
{
    ListElement *current = head;

    while (current->next != nullptr)
        removeAfter(current);
}

/**
 * @brief LinkedList insert function
 *
 * @param value A value to be inserted
 */
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

/**
 * @brief LinkedList element remover
 *
 * @param current The previous to the element which is to be removed
 */
void LinkedList::removeAfter(ListElement *current)
{
    ListElement *element = current->next;
    current->next = current->next->next;

    delete element;
}

/**
 * @brief LinkedList value remover
 *
 * @param value A value to be removed
 */
void LinkedList::remove(int value)
{
    ListElement *current = head;
    while (current->next != nullptr && current->next->value != value)
        current = current->next;

    if (current->next != nullptr)
        removeAfter(current);
}

/**
 * @brief LinkedList printer
 *
 * Displays the list on the console
 */
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

/**
 * @brief LinkedList length getter
 *
 * @return An integer, equal to the list's length
 */
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
