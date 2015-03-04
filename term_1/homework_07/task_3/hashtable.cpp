#include "hashtable.h"
#include "linkedList.h"
#include "string.h"

struct Hashtable
{
    LinkedList **list;
    int size;
    int numberOfElements;
};

unsigned int getHash(String *word, int modulo)
{
    char *string = toCharArray(word);
    int last = length(word) - 1;
    const int base = 8191 % modulo;
    unsigned int sum = string[last];
    while (last > 0)
    {
        last--;
        sum = (base * sum + string[last]) % modulo;
    }

    delete [] string;

    return sum;
}

Hashtable *createHashtable(int size)
{
    Hashtable *hashtable = new Hashtable;
    hashtable->size = size;
    hashtable->numberOfElements = 0;
    hashtable->list = new LinkedList*[hashtable->size];
    for (int i = 0; i < hashtable->size; i++)
        hashtable->list[i] = nullptr;

    return hashtable;
}

Hashtable *createHashtable()
{
    return createHashtable(3);
}

Hashtable *extendHashtable(Hashtable *hashtable)
{
    int newSize = hashtable->size * 3 / 2 + 1;
    Hashtable *newHashtable = createHashtable(newSize);
    for (int i = 0; i < hashtable->size; i++)
        if (hashtable->list[i] != nullptr)
            copyList(hashtable->list[i], newHashtable);

    return newHashtable;
}

void addValue(Hashtable *hashtable, String *value, int times)
{
    int valueHash = getHash(value, hashtable->size);
    if (hashtable->list[valueHash] == nullptr)
        hashtable->list[valueHash] = createLinkedList();
    bool contains = addValue(hashtable->list[valueHash], value, times);
    if (!contains)
        hashtable->numberOfElements++;
}

void addValue(Hashtable *hashtable, String *value)
{
    addValue(hashtable, value, 1);
}

void printHashtableWithTimes(Hashtable *hashtable)
{
    for (int i = 0; i < hashtable->size; i++)
        if (hashtable->list[i] != nullptr)
            printListWithTimes(hashtable->list[i]);
}

double loadFactor(Hashtable *hashtable)
{
    return (double) hashtable->numberOfElements / hashtable->size;
}

double averageListLength(Hashtable *hashtable)
{
    int listsNumber = 0;
    int totalLength = 0;
    for (int i = 0; i < hashtable->size; i++)
        if (hashtable->list[i] != nullptr)
        {
            listsNumber++;
            totalLength += getLength(hashtable->list[i]);
        }

    return (double) totalLength / listsNumber;
}

int maxListLength(Hashtable *hashtable)
{
    int maxLength = 0;
    for (int i = 0; i < hashtable->size; i++)
        if (hashtable->list[i] != nullptr)
        {
            int length = getLength(hashtable->list[i]);
            if (length > maxLength)
                maxLength = length;
        }

    return maxLength;
}

void printMaxListLengthValues(Hashtable *hashtable)
{
    int maxLength = 0;
    int maxIndex = -1;
    for (int i = 0; i < hashtable->size; i++)
        if (hashtable->list[i] != nullptr)
        {
            int length = getLength(hashtable->list[i]);
            if (length > maxLength)
            {
                maxIndex = i;
                maxLength = length;
            }
        }

    printList(hashtable->list[maxIndex]);
}

int getElementsNumber(Hashtable *hashtable)
{
    return hashtable->numberOfElements;
}

int emptyPositions(Hashtable *hashtable)
{
    int emptyPositions = 0;
    for (int i = 0; i < hashtable->size; i++)
        if (hashtable->list[i] == nullptr)
            emptyPositions++;

    return emptyPositions;
}

void deleteHashtable(Hashtable *hashtable)
{
    for (int i = 0; i < hashtable->size; i++)
        if (hashtable->list[i] != nullptr)
            deleteList(hashtable->list[i]);
    delete [] hashtable->list;
    delete hashtable;
}
