#include <iostream>
#include <fstream>
#include "binaryexpressiontree.h"

using namespace std;

char *extend(char *&array, int length, int maxLength)
{
    char *newArray = new char[maxLength];
    for (int i = 0; i < length; i++)
        newArray[i] = array[i];
    delete [] array;

    return newArray;
}

char *getStringFromStandartInput()
{
    int size = 1000;
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

int main()
{
    cout << "Enter the file path: ";
    char *path = getStringFromStandartInput();

    BinaryExpressionTree *tree = makeTreeFromFile(path);
    delete [] path;
    if (tree == nullptr)
    {
        cout << "No file found\n";
        return 0;
    }

    printPreorder(tree);
    cout << " = " << compute(tree);

    deleteTree(tree);

    return 0;
}
