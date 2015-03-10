#pragma once

class ArrayPrinter
{
public:
    virtual ~ArrayPrinter() {}
    virtual void printArray(int **array, int size) = 0;
};
