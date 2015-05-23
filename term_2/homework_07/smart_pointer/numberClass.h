#pragma once

class NumberClass
{
public:
    NumberClass(int value);
    ~NumberClass();
    int getValue() const;

private:
    int value = 0;
};
