#pragma once
#include "sorter.h"

class BogosortSorter : public Sorter
{
public:

    /**
     * @brief Bogosort
     *
     * Unbelievably ineffective sorting algorithm
     *
     * @param array Target array
     * @param size Size of the array
     */

    void sort(int *array, int size);

private:

    /**
     * @brief Array sortedness checker
     *
     * @param array Target array
     * @param size Size of the array
     * @return "true" if sorted, "false" otherwise
     */

    bool isSorted(int *array, int size);

    /**
     * @brief Array random shuffler
     *
     * Uses modern Knuth shuffle algorithm
     *
     * @param array Target array
     * @param size Size of the array
     */

    void shuffle(int *array, int size);
};
