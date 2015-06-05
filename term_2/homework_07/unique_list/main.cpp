#include <iostream>

#include "uniqueListTest.h"
#include "valueAlreadyExistsExceptionTest.h"
#include "valueNotFoundExceptionTest.h"

int main()
{
    UniqueListTest testList;
    QTest::qExec(&testList);
    std::cout << std::endl;

    ValueAlreadyExistsExceptionTest testExists;
    QTest::qExec(&testExists);
    std::cout << std::endl;

    ValueNotFoundExceptionTest testNotFound;
    QTest::qExec(&testNotFound);
    std::cout << std::endl;

    return 0;
}

