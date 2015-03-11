#pragma once
#include "listscomparator.h"

typedef LinkedList datatype;

class SortedSet : public ListsComparator, public LinkedList
{
public:
    SortedSet();
    ~SortedSet() {}
    void insert(LinkedList* value);
    void print() const;

private:
    struct ListElement;
    ListElement *head;
    void removeAfter(ListElement *current);
};
