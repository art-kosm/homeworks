#pragma once
#include "arrayPrinter.h"

class FilePrinter : public ArrayPrinter
{
public:

    /**
     * @brief File-tageted array printer
     *
     * If the path was not set, asks the user the file path and exports the array to this file
     * If file is not found, it will be created
     *
     * @param array Target array
     * @param size Size of the array
     */

    void printArraySpecified(int *array, int size, char *path = nullptr);

private:

    /**
     * @brief User-defined string getter
     *
     * @return A char array with got string
     */

    char *getStringFromStandardInput();

    /**
     * @brief Char array extender
     *
     * @param array
     * @param length Initial array length
     * @param maxLength Target length
     * @return Extended array
     */

    char *extend(char *&array, int length, int maxLength);
};
