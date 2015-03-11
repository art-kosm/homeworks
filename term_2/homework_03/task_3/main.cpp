#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "linkedlist.h"
#include "sortedset.h"

/**
 * @brief User-defined list count getter
 *
 * @return An integer, which will define the total number of lists
 */
int demandListCount()
{
    int listCount = 0;
    printf("Number of lists to be created: ");
    scanf("%d", &listCount);

    return listCount;
}

/**
 * @brief List initializer
 *
 * Asks user to define its length
 *
 * @return A list with certain amount of random 1-digit integers
 */
LinkedList *initializeList()
{
    LinkedList *list = new LinkedList();
    int listLength = 0;
    printf("List length: ");
    scanf("%d", &listLength);

    for (int j = 0; j < listLength; j++)
    {
        int value = rand() % 10;
        list->insert(value);
    }

    return list;
}

/**
 * @brief SortedSet tester
 *
 * @param listCount Total amount of lists, defined by user
 */
void testSortedSet(int listCount)
{
    SortedSet *set = new SortedSet();
    for (int i = 0; i < listCount; i++)
    {
        LinkedList *list = initializeList();
        set->insert(list);
    }

    printf("set contents:\n");
    set->print();

    delete set;
}

int main()
{
    srand(time(0));

    int listCount = demandListCount();
    testSortedSet(listCount);

    return 0;
}
