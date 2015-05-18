#include <cstdio>
#include "listsComparatorTest.h"
#include "linkedListTest.h"
#include "sortedSetTest.h"

int main()
{
    ListsComparatorTest testComparator;
    QTest::qExec(&testComparator);

    printf("\n");

    LinkedListTest testList;
    QTest::qExec(&testList);

    printf("\n");

    SortedSetTest testSet;
    QTest::qExec(&testSet);

    return 0;
}
