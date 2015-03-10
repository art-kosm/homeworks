#include <cstdio>
#include "consoleprinter.h"

/**
 * @brief Console-tageted array printer
 *
 * @param array Target array
 * @param size Size of the array
 */
void ConsolePrinter::printArray(int **array, int size)
{
    int line = size / 2;
    int column = line;
    int currentElement = 1;

    printElement(array, line, column, currentElement);
    currentElement++;

    if (size > 1)
    {
        line++;
        printElement(array, line, column, currentElement);
        currentElement++;
        column++;
        printElement(array, line, column, currentElement);
        currentElement++;

        for (int i = 0; i < 4; i++)
        {
            if (i < 2)
                line--;
            else
                column--;
            printElement(array, line, column, currentElement);
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
                printElement(array, line, column, currentElement);
                currentElement++;
            }
        }

        for (int i = 0; i < size - 1; i++)
        {
            line++;
            printElement(array, line, column, currentElement);
            currentElement++;
        }
    }

    printf("\n");
}

/**
 * @brief Current element printer
 *
 * @param array The array containing the element
 * @param line
 * @param column
 * @param currentElement The element number
 */
void ConsolePrinter::printElement(int **array, int line, int column, int currentElement) const
{
    printf("\nelement %d: %d", currentElement, array[line][column]);
}
