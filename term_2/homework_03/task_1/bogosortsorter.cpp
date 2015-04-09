#include "bogosortSorter.h"
#include <cstdlib>
#include <ctime>

void BogosortSorter::sort(int *array, int size)
{
    while (!isSorted(array, size))
        shuffle(array, size);
}

bool BogosortSorter::isSorted(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (array[i] > array[i + 1])
            return false;

    return true;
}

void BogosortSorter::shuffle(int *array, int size)
{
    srand(time(0));

    for (int i = size - 1; i >= 0; i--)
        swap(array[rand() % (i + 1)], array[i]);    ///swapping with the choosen random position (from 0 to i)
}
