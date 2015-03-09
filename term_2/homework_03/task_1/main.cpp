#include <cstdio>
#include <ctime>
#include "quicksortsorter.h"
#include "heapsortsorter.h"
#include "stupidsorter.h"
#include "bogosortsorter.h"

void quicksortTest(int *array, int size)
{
    printf("\nQuicksort: ");

    int quicksortArray[size];
    for (int i = 0; i < size; i++)
        quicksortArray[i] = array[i];

    Sorter *quicksortSorter = new QuicksortSorter();
    int startTime = time(0);
    quicksortSorter->sort(quicksortArray, size);
    int endTime = time(0);

    delete quicksortSorter;

    for (int i = 0; i < size; i++)
        printf("%d ", quicksortArray[i]);
    printf("\nTime elapsed: %d s\n\n", endTime - startTime);
}

void heapsortTest(int *array, int size)
{
    printf("Heapsort: ");

    int heapsortArray[size];
    for (int i = 0; i < size; i++)
        heapsortArray[i] = array[i];

    Sorter *heapsortSorter = new HeapsortSorter();
    int startTime = time(0);
    heapsortSorter->sort(heapsortArray, size);
    int endTime = time(0);

    delete heapsortSorter;

    for (int i = 0; i < size; i++)
        printf("%d ", heapsortArray[i]);
    printf("\nTime elapsed: %d s\n\n", endTime - startTime);
}

void stupidSortTest(int *array, int size)
{
    printf("Stupid sort: ");

    int stupidSortArray[size];
    for (int i = 0; i < size; i++)
        stupidSortArray[i] = array[i];

    Sorter *stupidSortSorter = new StupidSorter();
    int startTime = time(0);
    stupidSortSorter->sort(stupidSortArray, size);
    int endTime = time(0);

    delete stupidSortSorter;

    for (int i = 0; i < size; i++)
        printf("%d ", stupidSortArray[i]);
    printf("\nTime elapsed: %d s\n\n", endTime - startTime);
}

void bogosortTest(int *array, int size)
{
    printf("Bogosort: ");

    int bogosortArray[size];
    for (int i = 0; i < size; i++)
        bogosortArray[i] = array[i];

    Sorter *bogosortSorter = new BogosortSorter();
    int startTime = time(0);
    bogosortSorter->sort(bogosortArray, size);
    int endTime = time(0);

    delete bogosortSorter;

    for (int i = 0; i < size; i++)
        printf("%d ", bogosortArray[i]);
    printf("\nTime elapsed: %d s\n\n", endTime - startTime);
}


int main()
{
    int size = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];

    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    quicksortTest(array, size);
    heapsortTest(array, size);
    stupidSortTest(array, size);
    bogosortTest(array, size);

    return 0;
}
