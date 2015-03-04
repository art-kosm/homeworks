#include <iostream>
#include "fstream"
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

    int vertexes = 0;
    in >> vertexes;
    int edges = 0;
    in >> edges;

    Graph *graph = createGraph(vertexes);
    for (int i = 0; i < edges; i++)
    {
        int start = 0;
        in >> start;
        int end = 0;
        in >> end;
        int length = 0;\
        in >> length;

        addEdge(graph, start - 1, end - 1, length);
    }

    in.close();

    usePrimsAlgorithm(graph);

    deleteGraph(graph);

    return 0;
}
