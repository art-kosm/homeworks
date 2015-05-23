#pragma once
#include "sorter.h"

class HeapsortSorter : public Sorter
{
public:

    /**
     * @brief Heapsort
     *
     * An effective sorting algorithm
     *
     * @param array Target array
     * @param size Size of the array
     */

    void sort(int *array, int size);
};
