#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printElement(int **array, int line, int column, int currentElement)
{
    cout << "\nelement " << currentElement << ": " << array[line][column];
}

void printArray(int **array, int size)
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
}

int getSize()
{
    int size = 0;
    while (size % 2 == 0 || size < 0)
    {
        cout << "Enter N! ";
        cin >> size;
        if (size % 2 == 0)
            cout << "N is not odd. \n";
        if (size < 0)
            cout << "N is negative. \n";
    }
    return size;
}

int main()
{
    srand(time(0));

    int size = getSize();

    int **array = new int*[size];
    for(int i = 0; i < size; i++)
        array[i] = new int[size];

    cout << "\nArray: \n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            array[i][j] = rand() % 10;
            cout << array[i][j];
        }
        cout << "\n";
    }

    printArray(array, size);

    for(int i = 0; i < size; i++)
        delete [] array[i];
    delete [] array;

    return 0;
}

