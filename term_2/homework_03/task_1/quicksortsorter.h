#pragma once
#include "sorter.h"

class QuicksortSorter : public Sorter
{
public:
    QuicksortSorter() {}
    ~QuicksortSorter() {}
    void sort(dataType *array, int size);

private:
    void sort(dataType *array, int left, int right);
};
