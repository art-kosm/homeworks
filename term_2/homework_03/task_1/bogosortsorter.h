#pragma once
#include "sorter.h"

class BogosortSorter : public Sorter
{
public:
    BogosortSorter() {}
    ~BogosortSorter() {}
    void sort(dataType *array, int size);

private:
    bool isSorted(dataType *array, int size);
    void shuffle(dataType *array, int size);
};
