#include "linkedListStackTest.h"
#include "recursiveStackTest.h"
#include "calculatorTest.h"

int main()
{
    LinkedListStackTest testLinked;
    QTest::qExec(&testLinked);

    printf("\n");

    RecursiveStackTest testRecursive;
    QTest::qExec(&testRecursive);

    printf("\n");

    CalculatorTest testCalc;
    QTest::qExec(&testCalc);
}
