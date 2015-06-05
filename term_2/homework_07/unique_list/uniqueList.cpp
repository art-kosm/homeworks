#include "uniqueList.h"

bool UniqueList::add(const QString &value) throw (ValueAlreadyExistsException)
{
    if (LinkedList::add(value))
        throw ValueAlreadyExistsException(value);

    return true;
}

bool UniqueList::remove(const QString &value) throw (ValueNotFoundException)
{
    if (!LinkedList::remove(value))
        throw ValueNotFoundException(value);

    return true;
}
