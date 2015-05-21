#include <iostream>

class MyObject
{
public:
    ~MyObject()
    {
        std::cout << "Object deleted!\n";
    }
};

class MyException {};

void throwException()
{
    throw MyException();
}

int main()
{
    try
    {
        MyObject object1;
        MyObject object2;
        throwException();
    }
    catch (...)
    {
        std::cout << "\nException caught!";
    }

    return 0;
}
