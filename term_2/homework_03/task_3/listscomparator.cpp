#include "listsComparator.h"

bool ListsComparator::isGreaterThan(LinkedList *first, LinkedList *second)
{
    return first->getLength() > second->getLength();
}
