#pragma once
#include "sorter.h"

class StupidSorter : public Sorter
{
public:
    StupidSorter() {}
    ~StupidSorter() {}
    void sort(dataType *array, int size);
};
