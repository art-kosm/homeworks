#pragma once

class Sorter
{
public:
    virtual ~Sorter() {}

    /**
     * @brief Array sort function
     *
     * Sorts the array
     *
     * @param array Target array
     * @param size Size of the array
     */

    virtual void sort(int *array, int size) = 0;

protected:

    /**
     * @brief Elements swapper
     *
     * Swaps two elements of the array
     *
     * @param first element position
     * @param second element position
     */

    void swap(int &first, int &second);
};
