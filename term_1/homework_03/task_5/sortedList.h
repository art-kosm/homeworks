#pragma once

struct ListElement;
struct SortedList;

SortedList *createSortedList();
void addValue(SortedList *list, int value);
void removeValue(SortedList *list, int value);
void printList(SortedList *list);
void deleteNextElement(ListElement *element);
void deleteList(SortedList *list);
