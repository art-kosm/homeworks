#pragma once

class ArrayPrinter
{
public:
    virtual ~ArrayPrinter() {}

    /**
     * @brief A two-dimensional array printer
     *
     * @param array Target array
     * @param size Size of the array
     */

    void printArray(int **array, int size, char *path = nullptr);

    /**
     * @brief A resulting linear array printer
     *
     * @param array Target array
     * @param size Size of the array
     */

    virtual void printArraySpecified(int *array, int size, char *path = nullptr) = 0;
};
