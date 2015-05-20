#include "hashtable.h"

Hashtable::Hashtable()
{
    size = 3;
    elementsNumber = 0;

    list = new LinkedList*[size];
    for (int i = 0; i < size; i++)
        list[i] = nullptr;

    hash = defaultHash;
}

Hashtable::~Hashtable()
{
    for (int i = 0; i < size; i++)
        if (list[i] != nullptr)
            delete list[i];

    delete [] list;
}

void Hashtable::add(const QString &value)
{
    int valueHash = hash(value, size);

    if (list[valueHash] == nullptr)
        list[valueHash] = new LinkedList();

    bool contains = list[valueHash]->add(value);
    if (!contains)
        elementsNumber++;

    if (loadFactor() > 1)
        extend();
}

void Hashtable::remove(const QString &value)
{
    int valueHash = hash(value, size);

    if (list[valueHash] != nullptr)
    {
        bool contained = list[valueHash]->remove(value);
        if (contained)
            elementsNumber--;
    }
}

bool Hashtable::contains(const QString &value) const
{
    int valueHash = hash(value, size);

    return  list[valueHash] != nullptr &&
            list[valueHash]->contains(value);
}

int Hashtable::getElementsNumber() const
{
    return elementsNumber;
}

double Hashtable::loadFactor() const
{
    return (double) elementsNumber / size;
}

int Hashtable::conflicts() const
{
    int conflicts = 0;

    for (int i = 0; i < size; i++)
        if (list[i] != nullptr && list[i]->length() > 1)
            conflicts++;

    return conflicts;
}

int Hashtable::maxListLength() const
{
    int maxLength = 0;

    for (int i = 0; i < size; i++)
        if (list[i] != nullptr)
        {
            int length = list[i]->length();
            if (length > maxLength)
                maxLength = length;
        }

    return maxLength;
}

void Hashtable::setHashFunction(hashFunction function)
{
    hash = function;
    rebuild(size);
}

unsigned int Hashtable::defaultHash(const QString &value, int modulo)
{
    const unsigned int base = 8191 % modulo;

    int last = value.length() - 1;
    unsigned int sum = value.at(last).toLatin1() % modulo;

    while (last > 0)
    {
        last--;
        sum = (base * sum + value.at(last).toLatin1()) % modulo;
    }

    return sum;
}

void Hashtable::rebuild(int newSize)
{
    elementsNumber = 0;

    LinkedList **newList = new LinkedList*[newSize];
    for (int i = 0; i < newSize; i++)
        newList[i] = nullptr;

    for (int i = 0; i < size; i++)
        if (list[i] != nullptr)
        {
            int listLength = list[i]->length();
            for (int j = 0; j < listLength; j++)
            {
                QString value = list[i]->at(j);
                int valueHash = hash(value, newSize);

                if (newList[valueHash] == nullptr)
                    newList[valueHash] = new LinkedList();

                newList[valueHash]->add(value);
                elementsNumber++;
            }

            delete list[i];
        }

    delete [] list;

    list = newList;
    size = newSize;
}

void Hashtable::extend()
{
    int newSize = size * 3 / 2 + 1;
    rebuild(newSize);
}
