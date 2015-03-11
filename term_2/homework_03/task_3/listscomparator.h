#pragma once
#include "linkedlist.h"

class ListsComparator
{
public:
    virtual ~ListsComparator() {}

protected:
    static bool isGreaterThan(LinkedList *first, LinkedList *second);
};
