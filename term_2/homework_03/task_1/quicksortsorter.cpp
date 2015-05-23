#include "quicksortSorter.h"

void QuicksortSorter::sort(int *array, int size)
{
    sort(array, 0, size - 1);
}

void QuicksortSorter::sort(int *array, int left, int right)
{
    if (left < right)
    {
        int pivotIndex = (left + right) / 2;
        int pivotValue = array[pivotIndex];
        swap(array[pivotIndex], array[right]);
        int storeIndex = left;
        for (int i = left; i < right; i++)
            if (array[i] < pivotValue)
            {
                swap(array[i], array[storeIndex]);
                storeIndex++;
            }
        swap(array[storeIndex], array[right]);

        sort(array, left, storeIndex - 1);
        sort(array, storeIndex + 1, right);
    }
}
