#include <cstdio>
#include <fstream>
#include "filePrinter.h"

void FilePrinter::printArraySpecified(int *array, int size, char *path)
{
    bool userPath = false;

    if (path == nullptr)
    {
        printf("Enter the file path: ");
        path = getStringFromStandardInput();
        userPath = true;
    }

    std::ofstream out(path);

    if (userPath)
        delete [] path;

    for (int i = 0; i < size; i++)
        out << "element " << i + 1 << ": " << array[i] << "\n";

    out.close();
}

char *FilePrinter::getStringFromStandardInput()
{
    int size = 10;
    int length = 0;
    char *string = new char[size];

    while (true)
    {
        scanf("%c", &string[length]);
        length++;
        if (string[length - 1] == '\n')
        {
            string[length - 1] = '\0';
            break;
        }
        if (length == size)
        {
            size = size * 3 / 2 + 1;
            string = extend(string, length, size);
        }
    }

    return string;
}

char *FilePrinter::extend(char *&array, int length, int maxLength)
{
    char *newArray = new char[maxLength];
    for (int i = 0; i < length; i++)
        newArray[i] = array[i];

    delete [] array;

    return newArray;
}
