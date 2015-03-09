#include "heapsortsorter.h"

void HeapsortSorter::sort(dataType *array, int size)
{
    if (size > 1)
    {
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            int leftChild = 2 * i + 1;
            if (leftChild < size && array[leftChild] > array[i])
                swap(array[i], array[leftChild]);

            int rightChild = 2 * i + 2;
            if (rightChild < size && array[rightChild] > array[i])
                swap(array[i], array[rightChild]);
        }

        swap(array[0], array[size - 1]);
        sort(array, size - 1);
    }
}
