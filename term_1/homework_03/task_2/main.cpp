#include <iostream>

using namespace std;

int getStringLength(char string[])
{
    int length = 0;
    for (int i = 0; string[i] != '\0'; i++)
        length++;
    return length;
}

void quicksort(char array[], int left, int right)
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
    const int size = 65536;

    char string1[size];
    cout << "Enter the first string: ";
    cin >> string1;

    char string2[size];
    cout << "Enter the second srting: ";
    cin >> string2;

    int string1Length = getStringLength(string1);
    int string2Length = getStringLength(string2);

    bool isPossible = false;
    if (string1Length == string2Length)
    {
        quicksort(string1, 0, string1Length - 1);
        quicksort(string2, 0, string2Length - 1);

        int equalLetters = 0;

        for (int i = 0; i < string1Length; i++)
        {
            if (string1[i] != string2[i])
                break;
            equalLetters++;
        }

        if (equalLetters == string1Length)
            isPossible = true;
    }

    if (isPossible)
        cout << "It is possible. \n";
    else
        cout << "It is not possible. \n";

    return 0;
}

