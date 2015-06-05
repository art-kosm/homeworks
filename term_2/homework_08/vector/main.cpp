#include <iostream>
#include "vectorTest.h"

int main()
{
    VectorTest testVector;
    QTest::qExec(&testVector);
    std::cout << std::endl;

    return 0;
}
