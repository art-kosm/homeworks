#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "arrayPrinter.h"
#include "consolePrinter.h"
#include "filePrinter.h"
#include "filePrinterTest.h"

/**
 * @brief The Mode enum
 *
 * Defines the action to be done with array
 */

enum Mode
{
    printToConsole,
    printToFile,
    undefined
};

/**
 * @brief An odd positive integer demander
 *
 * @return An integer, which will be used as size
 */

int demandOddPositiveInteger()
{
    int result = 0;
    while (result % 2 == 0 || result < 0)
    {
        printf("Enter N! ");
        scanf("%d", &result);
        if (result % 2 == 0)
            printf("N is not odd. \n");
        if (result < 0)
            printf("N is negative. \n");
    }
    return result;
}

/**
 * @brief Array initializer
 *
 * @param size An integer got from getSize()
 * @return A 2-dimensional array with random 1-digit integers
 */

int **initializeArray(int size)
{
    int **array = new int*[size];
    for(int i = 0; i < size; i++)
        array[i] = new int[size];

    printf("\nArray: \n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            array[i][j] = rand() % 10;
            printf("%d", array[i][j]);
        }
        printf("\n");
    }

    return array;
}

/**
 * @brief Processing mode demander
 *
 * @return The mode in which array will be printed
 */

Mode demandMode()
{
    Mode mode = undefined;

    printf("Choose your destiny: \n0 -- print to console \n1 -- print to a file\n\n");
    while (mode != printToConsole && mode != printToFile)
    {
        int result = 0;
        scanf("%d", &result);
        mode = Mode(result);

        ///cleaning input after scanning with Mode()
        char c = 0;
        scanf("%c", &c);

        if (mode != printToConsole && mode != printToFile)
            printf("Incorrect input\n");
    }

    return mode;
}

/**
 * @brief Array print switcher
 *
 * Prints array in the mode specified by the user
 *
 * @param mode
 * @param array Array to be printed
 * @param size Size of the array
 */

void printArrayInSpecifiedMode(Mode mode, int **array, int size)
{
    switch (mode)
    {
        case printToConsole:
        {
            ArrayPrinter *printer = new ConsolePrinter();
            printer->printArray(array, size);

            delete printer;
        } break;

        case printToFile:
        {
            ArrayPrinter *printer = new FilePrinter();
            printer->printArray(array, size);

            delete printer;
        } break;

        default:
        break;
    }
}

/**
 * @brief User activity processer
 *
 * Demands the array size and the mode and prints the array in the specified mode
 */

void processUserActivity()
{
    srand(time(0));

    int size = demandOddPositiveInteger();
    int **array = initializeArray(size);

    Mode mode = demandMode();

    printArrayInSpecifiedMode(mode, array, size);

    for(int i = 0; i < size; i++)
        delete [] array[i];
    delete [] array;
}

int main()
{
    FilePrinterTest testPrinter;
    QTest::qExec(&testPrinter);

    printf("\n");

    processUserActivity();

    return 0;
}
