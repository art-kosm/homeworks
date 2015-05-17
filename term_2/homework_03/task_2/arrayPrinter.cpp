#include "arrayPrinter.h"

void ArrayPrinter::printArray(int **array, int size, char *path)
{
    int elementsNumber = size * size;
    int *elementsOrdered = new int[elementsNumber];

    int line = size / 2;
    int column = line;
    int currentElement = 0;

    elementsOrdered[currentElement] = array[line][column];
    currentElement++;

    if (size > 1)
    {
        line++;
        elementsOrdered[currentElement] = array[line][column];
        currentElement++;
        column++;
        elementsOrdered[currentElement] = array[line][column];
        currentElement++;

        for (int i = 0; i < 4; i++)
        {
            if (i < 2)
                line--;
            else
                column--;
            elementsOrdered[currentElement] = array[line][column];
            currentElement++;
        }

        for (int i = 3; i < size; i += 2)
        {
            for (int j = 0; j < 4 * i + 2; j++)
            {
                if (j < i)
                    line++;
                else if (j < 2 * i)
                    column++;
                else if (j < 3 * i + 1)
                    line--;
                else
                    column--;
                elementsOrdered[currentElement] = array[line][column];
                currentElement++;
            }
        }

        for (int i = 0; i < size - 1; i++)
        {
            line++;
            elementsOrdered[currentElement] = array[line][column];
            currentElement++;
        }
    }

    printArraySpecified(elementsOrdered, elementsNumber, path);

    delete [] elementsOrdered;
}
