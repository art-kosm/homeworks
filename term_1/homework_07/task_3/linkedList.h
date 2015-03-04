#pragma once

struct ListElement;
struct LinkedList;
struct String;
struct Hashtable;

LinkedList *createLinkedList();
bool addValue(LinkedList *list, String *value);
bool addValue(LinkedList *list, String *value, int times);
String *getValue(LinkedList *list, int index);
int getTimes(LinkedList *list, int index);
int getLength(LinkedList *list);
void removeValue(LinkedList *list, String *value);
void printList(LinkedList *list);
void printListWithTimes(LinkedList *list);
void copyList(LinkedList *list, Hashtable *hashtable);
void deleteList(LinkedList *list);
