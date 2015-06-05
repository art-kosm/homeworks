#include <iostream>
#include "setTest.h"

int main()
{
    SetTest testSet;
    QTest::qExec(&testSet);
    std::cout << std::endl;

    return 0;
}

