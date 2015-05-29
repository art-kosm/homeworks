#include <iostream>
#include "numberClass.h"
#include "sharedPointer.h"

void createNewFunctionPointer(NumberClass *object)
{
    std::cout << std::endl << "Function has been called" << std::endl;
    SharedPointer<NumberClass> pointerFoo(object);
    std::cout << "First object count: " << pointerFoo.count() << std::endl;
}

int main()
{
    SharedPointer<NumberClass> firstObjectPointer1(new NumberClass(7));
    std::cout << "First object count: " << firstObjectPointer1.count() << std::endl;

    SharedPointer<NumberClass> firstObjectPointer2(firstObjectPointer1);
    std::cout << "First object count: " << firstObjectPointer1.count() << std::endl;

    SharedPointer<NumberClass> firstObjectPointer3 = firstObjectPointer2;
    std::cout << "First object count: " << firstObjectPointer1.count() << std::endl << std::endl;

    SharedPointer<NumberClass> secondObjectPointer(new NumberClass(-7));
    std::cout << "Second object count: " << secondObjectPointer.count() << std::endl << std::endl;

    NumberClass *thirdObject = new NumberClass(35);
    SharedPointer<NumberClass> thirdObjectPointer1(thirdObject);
    SharedPointer<NumberClass> thirdObjectPointer2(thirdObject);
    SharedPointer<NumberClass> thirdObjectPointer3(thirdObject);

    std::cout << "Third object count: " << thirdObjectPointer1.count() << std::endl;
    std::cout << "Third object value: " << thirdObjectPointer2->getValue() << std::endl << std::endl;

    delete thirdObject;
    std::cout << "Third object count: " << thirdObjectPointer2.count() << std::endl;
    std::cout << "Third object value: " << thirdObjectPointer3->getValue() << std::endl << std::endl;

    std::cout << "firstObjectPointer1 object value: " << firstObjectPointer1->getValue() << std::endl;
    std::cout << "firstObjectPointer2 object value: " << firstObjectPointer2->getValue() << std::endl;
    std::cout << "firstObjectPointer3 object value: " << firstObjectPointer3->getValue() << std::endl;
    std::cout << "secondObjectPointer object value: " << secondObjectPointer->getValue() << std::endl;

    createNewFunctionPointer(&*firstObjectPointer1);
    std::cout << "Function has finished" << std::endl;
    std::cout << "First object count: " << firstObjectPointer1.count() << std::endl;
    std::cout << "Second object count: " << secondObjectPointer.count() << std::endl;

    return 0;
}
