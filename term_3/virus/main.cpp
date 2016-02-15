#include <cstdlib>
#include <ctime>
#include "networkTest.h"

int main()
{
    srand(time(0));
    NetworkTest testNetwork;
    QTest::qExec(&testNetwork);

    return 0;
}
