#include <cstdio>
#include "consolePrinter.h"

void ConsolePrinter::printArraySpecified(int *array, int size, char *path)
{
    for (int i = 0; i < size; i++)
        printf("\nelement %d: %d", i + 1, array[i]);

    printf("\n");
}
