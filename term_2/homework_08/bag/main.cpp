#include <iostream>
#include "treeTest.h"

int main()
{
    TreeTest testTree;
    QTest::qExec(&testTree);
    std::cout << std::endl;

    return 0;
}
