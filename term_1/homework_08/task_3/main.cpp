#include <iostream>
#include <fstream>
#include "graph.h"

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

int convertToNumber(char character)
{
    int difference = '1' - 1;
    return character - difference;
}

int main()
{
    cout << "Enter the file path: ";
    char *path = getStringFromStandartInput();
    ifstream in(path);
    delete [] path;
    if (in == nullptr)
    {
        cout << "No file found\n";
        return 0;
    }

    int size = 0;
    char c = '\0';
    in >> noskipws >> c;
    while (c != '\n')
    {
        if (c != ' ')
            size++;
        in >> c;
    }
    in.seekg(0, ios::beg);

    Graph *graph = createGraph(size);
    int firstVertex = 0;
    int secondVertex = 0;
    while (firstVertex < size)
    {
        in >> c;
        if (in.eof())
            break;
        if (c == '0' || c == '1')
        {
            if (c == '1')
                addEdge(graph, firstVertex, secondVertex);
            secondVertex++;
        }
        else if (c == '\n')
        {
            firstVertex++;
            secondVertex = 0;
        }

    }
    in.close();

    findComponents(graph);
    printComponents(graph);

    deleteGraph(graph);

    return 0;
}
