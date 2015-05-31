#pragma once

#include "linkedList.h"
#include "valueAlreadyExistsException.h"
#include "valueNotFoundException.h"

class UniqueList : public LinkedList
{
public:
    using LinkedList::LinkedList;

    /**
     * @brief Value adder
     *
     * Adds only currently non-existing value
     *
     * @param value QString to be added
     * @return true
     */

    bool add(const QString&) throw (ValueAlreadyExistsException);

    /**
     * @brief Value remover
     *
     * Removes each element with the specified value (if it somehow
     * happened to appear in the list)
     *
     * @param value QString to be removed
     * @return true
     */

    bool remove(const QString&) throw (ValueNotFoundException);
};
