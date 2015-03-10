#include <cstdio>
#include <fstream>
#include "fileprinter.h"

/**
 * @brief File-tageted array printer
 *
 * Asks user the file path and exports an array to this file
 * If file is not found, it will be created
 *
 * @param array Target array
 * @param size Size of the array
 */
void FilePrinter::printArray(int **array, int size)
{
    printf("Enter the file path: ");
    char *path = getStringFromStandardInput();
    std::ofstream out(path);
    delete [] path;

    int line = size / 2;
    int column = line;
    int currentElement = 1;

    out << "element " << currentElement << ": " << array[line][column];
    currentElement++;

    if (size > 1)
    {
        line++;
        out << "\nelement " << currentElement << ": " << array[line][column];
        currentElement++;
        column++;
        out << "\nelement " << currentElement << ": " << array[line][column];
        currentElement++;

        for (int i = 0; i < 4; i++)
        {
            if (i < 2)
                line--;
            else
                column--;
            out << "\nelement " << currentElement << ": " << array[line][column];
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
                out << "\nelement " << currentElement << ": " << array[line][column];
                currentElement++;
            }
        }

        for (int i = 0; i < size - 1; i++)
        {
            line++;
            out << "\nelement " << currentElement << ": " << array[line][column];
            currentElement++;
        }
    }

    out.close();
}

/**
 * @brief User-defined string getter
 *
 * @return A char array with got string
 */
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

/**
 * @brief Char array extender
 *
 * @param array
 * @param length Initial array length
 * @param maxLength Target length
 * @return Extended array
 */
char *FilePrinter::extend(char *&array, int length, int maxLength)
{
    char *newArray = new char[maxLength];
    for (int i = 0; i < length; i++)
        newArray[i] = array[i];

    delete [] array;

    return newArray;
}
