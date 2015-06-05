#include <iostream>
#include <cstdlib>
#include <ctime>
#include "numberClass.h"
#include "sharedPointer.h"
#include "smartPointerTest.h"

int main()
{
    SharedPointerTest testPointer;
    QTest::qExec(&testPointer);
    std::cout << std::endl;

    SharedPointer<NumberClass> firstObjectPointer1(new NumberClass(16));
    std::cout << "First object count: " << firstObjectPointer1.count() << std::endl;

    SharedPointer<NumberClass> firstObjectPointer2(firstObjectPointer1);
    std::cout << "First object count: " << firstObjectPointer1.count() << std::endl;

    SharedPointer<NumberClass> firstObjectPointer3 = firstObjectPointer2;
    std::cout << "First object count: " << firstObjectPointer1.count() << std::endl;

    SharedPointer<NumberClass> secondObjectPointer(new NumberClass(-21));
    std::cout << "Second object count: " << secondObjectPointer.count() << std::endl << std::endl;

    std::cout << "firstObjectPointer1 object value: " << firstObjectPointer1->getValue() << std::endl;
    std::cout << "firstObjectPointer2 object value: " << firstObjectPointer2->getValue() << std::endl;
    std::cout << "firstObjectPointer3 object value: " << firstObjectPointer3->getValue() << std::endl;
    std::cout << "secondObjectPointer object value: " << secondObjectPointer->getValue() << std::endl << std::endl;

    return 0;
}
