#include <iostream>
#include "numberClass.h"

NumberClass::NumberClass(int value)
{
    this->value = value;
}

NumberClass::~NumberClass()
{
    std::cout << "Object has been deleted" << std::endl;
}

int NumberClass::getValue() const
{
    return value;
}
