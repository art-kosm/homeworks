#pragma once

class NumberClass
{
public:
    NumberClass(int value) : value(value) {}

    ~NumberClass()
    {
        std::cout << "Object has been deleted" << std::endl;
    }

    int getValue() const
    {
        return value;
    }

private:
    int value = 0;
};
