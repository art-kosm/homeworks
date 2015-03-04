#include <iostream>
#include <limits>
#include "graph.h"
#include "stack.h"

struct Graph
{
    Vertex **vertexes;
    int **edges;
    int size;    
};

struct Vertex
{
    int distance;
    bool visited;
    int previous;
    int position;
};

Vertex *createVertex()
{
    Vertex *vertex = new Vertex;
    vertex->distance = std::numeric_limits<int>::max();
    vertex->visited = false;
    vertex->previous = -1;
    vertex->position = -1;

    return vertex;
}

Graph *createGraph(int size)
{
    Graph *graph = new Graph;
    Vertex **vertexes = new Vertex*[size];
    int **edges = new int*[size];
    for (int i = 0; i < size; i++)
    {
        edges[i] = new int[size];
        for (int j = 0; j < size; j++)
            edges[i][j] = -1;
        vertexes[i] = createVertex();
    }
    graph->vertexes = vertexes;
    graph->edges = edges;
    graph->size = size;

    return graph;
}

void addEdge(Graph *graph, int vertex1, int vertex2, int length)
{
    graph->edges[vertex1][vertex2] = length;
    graph->edges[vertex2][vertex1] = length;
}

void usePrimsAlgorithm(Graph *graph)
{
    graph->vertexes[0]->visited = true;

    int size = graph->size;

    Stack *neighbours = createStack();
    for (int i = 0; i < size; i++)
        if (graph->vertexes[i]->visited)
            for (int j = 0; j < size; j++)
                if (graph->edges[i][j] >= 0 && !graph->vertexes[j]->visited)
                    push(neighbours, i, j, graph->edges[i][j]);

    int minStart = -1;
    int minEnd = -1;
    int minDistance = std::numeric_limits<int>::max();
    while (!isEmpty(neighbours))
    {
        int start = getTopStartValue(neighbours);
        int end = getTopEndValue(neighbours);
        int distance = getTopDistance(neighbours);
        pop(neighbours);
        if (distance < minDistance)
        {
            minDistance = distance;
            minStart = start;
            minEnd = end;
        }
    }

    graph->vertexes[minEnd]->visited = true;

    deleteStack(neighbours);

    if (minStart != -1)
        std::cout << minStart + 1 << " " << minEnd + 1 << " (distance: " << minDistance << ")\n";

    for (int i = 0; i < size; i++)
        if (!graph->vertexes[i]->visited)
        {
            usePrimsAlgorithm(graph);
            break;
        }
}

void deleteGraph(Graph *graph)
{
    for (int i = 0; i < graph->size; i++)
    {
        delete [] graph->vertexes[i];
        delete [] graph->edges[i];
    }
    delete [] graph->vertexes;
    delete [] graph->edges;
    delete graph;
}
