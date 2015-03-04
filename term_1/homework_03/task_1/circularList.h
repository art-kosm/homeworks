#pragma once

struct ListElement
{
    int value;
    ListElement *next;
};

struct CircularList
{
    ListElement *head;
};

CircularList *createCircularList();
ListElement *getHead(CircularList *list);
ListElement *getFirst(CircularList *list);
ListElement *getLast(CircularList *list);
ListElement *getNextElement(ListElement *current);
int getValue(ListElement *current);
void addValue(CircularList *list, int value);
void deleteNextElement(CircularList *list, ListElement *element);
void deleteList(CircularList *list);
