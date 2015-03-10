#pragma once
#include "arrayprinter.h"

class FilePrinter : public ArrayPrinter
{
public:
    FilePrinter() {}
    ~FilePrinter() {}
    void printArray(int **array, int size);

private:
    char *getStringFromStandardInput();
    char *extend(char *&array, int length, int maxLength);
};
