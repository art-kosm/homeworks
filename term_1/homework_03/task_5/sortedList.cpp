#include <iostream>
#include "sortedList.h"

using namespace std;

struct ListElement
{
    int value;
    ListElement *next;
};

struct SortedList
{
    ListElement *head;
};

SortedList *createSortedList()
{
    ListElement *guard = new ListElement;
    SortedList *list = new SortedList;
    guard->value = 0;
    guard->next = nullptr;
    list->head = guard;
    return list;
}

void addValue(SortedList *list, int value)
{
    ListElement *current = list->head;
    while (current->next != nullptr && current->next->value < value)
        current = current->next;
    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->next = current->next;
    current->next = newElement;
    cout << "Value added.\n";
}

void removeValue(SortedList *list, int value)
{
    ListElement *current = list->head;
    while (current->next != nullptr && current->next->value != value)
        current = current->next;
    if (current->next != nullptr)
    {
        deleteNextElement(current);
        cout << "Value removed!\n";
    }
    else
        cout << "Value not found.\n";
}

void printList(SortedList *list)
{
    ListElement *current = list->head->next;
    while (current != nullptr)
    {
        cout << current->value << "\n";
        current = current->next;
    }
}

void deleteNextElement(ListElement *current)
{
    ListElement *element = current->next;
    current->next = current->next->next;
    delete element;
}

void deleteList(SortedList *list)
{
    ListElement *current = list->head;
    while (current->next != nullptr)
        deleteNextElement(current);
}
