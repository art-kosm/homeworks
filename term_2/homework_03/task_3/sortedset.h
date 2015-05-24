#pragma once
#include "linkedList.h"

class SortedSet
{
public:

    /**
     * @brief SortedSet constructor
     *
     * Almost identical to LinkedList' one
     */

    SortedSet();

    /**
     * @brief SortedSet destructor
     *
     * Identical to LinkedList' one
     */

    ~SortedSet();

    /**
     * @brief SortedSet insert function
     *
     * Inserts the list, saving the set sorted
     *
     * @param value The list to be inserted
     */

    void insert(LinkedList* value);

    /**
     * @brief SortedSet printer
     *
     * Displays the set on the console, printing it list by list
     */

    void print() const;

    /**
     * @brief SortedSet at function
     *
     * @param index of the position
     * @return List at the certain position
     */

    LinkedList *at(int index);

private:

    /**
     * @brief ListElement struct
     *
     * Almost identical to LinkedList' one, contains a linked list instead of integer
     */

    struct ListElement;

    ListElement *head;

    /**
     * @brief SortedSet element remover
     *
     * Identical to LinkedList' one, except its own ListElement structure
     *
     * @param current The previous to the element which is to be removed
     */

    void removeAfter(ListElement *current);
};
