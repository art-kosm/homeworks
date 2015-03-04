#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void quicksort(int array[], int left, int right)
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

        quicksort(array, left, storeIndex - 1);
        quicksort(array, storeIndex + 1, right);
    }
}

int main()
{
    srand(time(0));

    const int size = rand() % 10 + 10;
    int array[size];
    for (int i = 0; i < size; i++)
        array[i] = rand();

    cout << "Unsorted array: \n";
    for (int i = 0; i < size; i++)
        cout << array[i] << '\n';

    quicksort(array, 0, size - 1);

    cout << "Sorted array: \n";
    for (int i = 0; i < size; i++)
        cout << array[i] << '\n';

    return 0;
}

