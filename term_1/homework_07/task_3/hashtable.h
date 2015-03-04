#pragma once

struct Hashtable;
struct String;

unsigned int getHash(String *word, int modulo);
Hashtable *createHashtable();
Hashtable *extendHashtable(Hashtable *hashtable);
void addValue(Hashtable *hashtable, String *value);
void addValue(Hashtable *hashtable, String *value, int times);
void printHashtableWithTimes(Hashtable *hashtable);
double loadFactor(Hashtable *hashtable);
double averageListLength(Hashtable *hashtable);
int maxListLength(Hashtable *hashtable);
void printMaxListLengthValues(Hashtable *hashtable);
int getElementsNumber(Hashtable *hashtable);
int emptyPositions(Hashtable *hashtable);
void deleteHashtable(Hashtable *hashtable);
