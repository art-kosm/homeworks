#pragma once
#include "sorter.h"

class StupidSorter : public Sorter
{
public:

    /**
     * @brief Stupid sort
     *
     * An uneffective sorting algorithm
     *
     * @param array Target array
     * @param size Size of the array
     */

    void sort(int *array, int size);
};
