#pragma once
#include "linkedList.h"

class ListsComparator
{
public:

    /**
     * @brief Lists comparator itself, the function, deciding whether the first list is longer than the second one
     *
     * @param first
     * @param second
     * @return Result of comparison
     */

    static bool isGreaterThan(LinkedList *first, LinkedList *second);
};
