#include <iostream>
#include "bagTest.h"

using namespace std;

int main()
{
    BagTest testBag;
    QTest::qExec(&testBag);
    std::cout << std::endl;

    return 0;
}
