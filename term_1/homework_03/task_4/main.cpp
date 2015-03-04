#include <iostream>

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

void fixZeros(int digits[])
{
    int zeros = 0;
    while (digits[zeros] == 0)
        zeros++;
    swap(digits[0], digits[zeros]);
}

int main()
{
    int n = 0;
    cout << "Enter the number: ";
    cin >> n;

    const int size = 65536;
    int digits[size];

    int nLength = 0;
    for (nLength; n > 0; nLength++)
    {
        digits[nLength] = n % 10;
        n /= 10;
    }

    quicksort(digits, 0, nLength - 1);
    fixZeros(digits);

    cout << "Minimal number: ";
    for (int i = 0; i < nLength; i++)
        cout << digits[i];
    return 0;
}
