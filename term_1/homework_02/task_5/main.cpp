#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void heapsort(int array[], int size)
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
        heapsort(array, size - 1);
    }
}

int main()
{
    srand(time(0));

    const int size = rand() % 16 + 1;
    int array[size];
    for (int i = 0; i < size; i++)
        array[i] = rand() % 128 - 64;

    cout << "Unsorted array: \n";
    for (int i = 0; i < size; i++)
        cout << array[i] << '\n';

    heapsort(array, size);

    cout << "Sorted array: \n";
    for (int i = 0; i < size; i++)
        cout << array[i] << '\n';

    return 0;
}
