#include "stupidsorter.h"

void StupidSorter::sort(dataType *array, int size)
{
    int currentElement = 0;

    while (currentElement < size - 1)
        if (array[currentElement] > array[currentElement + 1])
        {
            swap(array[currentElement], array[currentElement + 1]);
            currentElement = 0;
        }
        else
            currentElement++;
}
