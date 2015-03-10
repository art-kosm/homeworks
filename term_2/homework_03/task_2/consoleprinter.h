#pragma once
#include "arrayprinter.h"

class ConsolePrinter : public ArrayPrinter
{
public:
    ConsolePrinter() {}
    ~ConsolePrinter() {}
    void printArray(int **array, int size);

private:
    void printElement(int **array, int line, int column, int currentElement) const;
};
