#include <iostream>
#include "circularList.h"

using namespace std;

CircularList *createCircularList()
{
    ListElement *guard = new ListElement;
    CircularList *list = new CircularList;
    guard->value = 0;
    guard->next = nullptr;
    list->head = guard;
    return list;
}

void addValue(CircularList *list, int value)
{
    ListElement *newElement = new ListElement;
    newElement->value = value;
    if (list->head->next == nullptr)
    {
        newElement->next = newElement;
        list->head = newElement;
    }
    else
    {
        newElement->next = list->head->next;
        ListElement *current = list->head->next;
        while (current->next != list->head->next)
            current = current->next;
        current->next = newElement;
    }
}

void deleteNextElement(CircularList *list, ListElement *current)
{
    if (current->next == getFirst(list))
    {
        ListElement *last = getLast(list);
        last->next = current->next->next;
    }
    else
    {
        ListElement *element = current->next;
        current->next = current->next->next;
        delete element;
    }
}

ListElement *getHead(CircularList *list)
{
    return list->head;
}


ListElement *getNextElement(ListElement *current)
{
    return current->next;
}


void deleteList(CircularList *list)
{
    delete list->head->next;
    delete list->head;
    delete list;
}


ListElement *getFirst(CircularList *list)
{
    return list->head->next;
}


ListElement *getLast(CircularList *list)
{
    ListElement *last = getFirst(list);
    while (last->next != list->head->next)
        last = last->next;
    return last;
}


int getValue(ListElement *current)
{
    return current->value;
}
