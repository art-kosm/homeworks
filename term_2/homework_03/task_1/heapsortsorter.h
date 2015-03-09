#pragma once
#include "sorter.h"

class HeapsortSorter : public Sorter
{
public:
    HeapsortSorter() {}
    ~HeapsortSorter() {}
    void sort(dataType *array, int size);
};
