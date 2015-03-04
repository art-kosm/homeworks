#include <iostream>
#include "linkedList.h"
#include "string.h"
#include "hashtable.h"

using namespace std;

struct ListElement
{
    String *value;
    int times;
    ListElement *next;
};

struct LinkedList
{
    ListElement *head;
};

LinkedList *createLinkedList()
{
    ListElement *guard = new ListElement;
    LinkedList *list = new LinkedList;
    guard->value = nullptr;
    guard->times = 0;
    guard->next = nullptr;
    list->head = guard;

    return list;
}

bool contains(LinkedList *list, String *value)
{
    ListElement *current = list->head;
    while (current != nullptr && !equals(value, current->value))
        current = current->next;

    return equals(value, current->value);
}

ListElement *find(LinkedList *list, String *value)
{
    ListElement *current = list->head;
    while (current->next != nullptr && !equals(value, current->next->value))
        current = current->next;

    return current;
}

bool addValue(LinkedList *list, String *value, int times)
{
    ListElement *element = find(list, value);
    if (element->next == nullptr)
    {
        ListElement *newElement = new ListElement;
        newElement->value = clone(value);
        newElement->times = times;
        newElement->next = nullptr;
        element->next = newElement;
    }
    else
    {
        element->next->times += times;
        return true;
    }

    return false;
}

bool addValue(LinkedList *list, String *value)
{
    return addValue(list, value, 1);
}

String *getValue(LinkedList *list, int index)
{
    ListElement *current = list->head->next;
    for (int i = 0; i < index; i++)
        if (current->next != nullptr)
            current = current->next;
        else
            return nullptr;

    return clone(current->value);
}

int getTimes(LinkedList *list, int index)
{
    ListElement *current = list->head->next;
    for (int i = 0; i < index; i++)
        if (current->next != nullptr)
            current = current->next;
        else
            return 0;

    return current->times;
}

int getLength(LinkedList *list)
{
    int length = 0;
    ListElement *current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
        length++;
    }

    return length;
}

void deleteNextElement(ListElement *current)
{
    ListElement *element = current->next;
    current->next = current->next->next;
    deleteString(element->value);
    delete element;
}

void removeValue(LinkedList *list, String *value)
{
    ListElement *current = list->head;
    while (current != nullptr && current->next != nullptr)
    {
        if (current->next->value == value)
            deleteNextElement(current);
        current = current->next;
    }
}

void printList(LinkedList *list)
{
    ListElement *current = list->head->next;
    while (current != nullptr)
    {
        cout << toCharArray(current->value) << "\n";
        current = current->next;
    }
}

void printListWithTimes(LinkedList *list)
{
    ListElement *current = list->head->next;
    while (current != nullptr)
    {
        cout << toCharArray(current->value) << ": " << current->times << "\n";
        current = current->next;
    }
}

void copyList(LinkedList *list, Hashtable *hashtable)
{
    ListElement *current = list->head->next;
    while (current != nullptr)
    {
        addValue(hashtable, current->value, current->times);
        current = current->next;
    }
}

void deleteList(LinkedList *list)
{
    ListElement *current = list->head;
    while (current->next != nullptr)
        deleteNextElement(current);
    delete list->head;
    delete list;
}
