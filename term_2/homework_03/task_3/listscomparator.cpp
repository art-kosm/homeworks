#include "listscomparator.h"

/**
 * @brief Lists comparator itself, the function, deciding whether the first list is longer than the second one
 *
 * @param first
 * @param second
 * @return Result of comparison
 */
bool ListsComparator::isGreaterThan(LinkedList *first, LinkedList *second)
{
    return first->getLength() >= second->getLength();
}
