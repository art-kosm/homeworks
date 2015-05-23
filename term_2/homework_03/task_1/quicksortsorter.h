#pragma once
#include "sorter.h"

class QuicksortSorter : public Sorter
{
public:

    /**
     * @brief Quicksort basic function
     *
     * Sorts the whole array
     * An effective sorting algorithm
     *
     * @param array Target array
     * @param size Size of the array
     */

    void sort(int *array, int size);

private:

    /**
     * @brief Quicksort special function
     *
     * Sorts the array from left to right element (including both)
     *
     * @param array Target array
     * @param left The first element of a part which is to be sorted
     * @param right The last element of a part which is to be sorted
     */

    void sort(int *array, int left, int right);
};
