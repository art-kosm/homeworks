#include "bogosortSorterTest.h"
#include "heapsortSorterTest.h"
#include "quicksortSorterTest.h"
#include "stupidSorterTest.h"

int main()
{
    HeapsortSorterTest testHeap;
    QTest::qExec(&testHeap);
    printf("\n");

    QuicksortSorterTest testQuick;
    QTest::qExec(&testQuick);
    printf("\n");

    StupidSorterTest testStupid;
    QTest::qExec(&testStupid);
    printf("\n");

    BogosortSorterTest testBogo;
    QTest::qExec(&testBogo);
}
