#pragma once
#include "arrayPrinter.h"

class ConsolePrinter : public ArrayPrinter
{
public:

    /**
     * @brief Console-tageted array printer
     *
     * @param array Target array
     * @param size Size of the array
     */

    void printArraySpecified(int *array, int size, char *path = nullptr);
};
