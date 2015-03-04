#include <iostream>
#include "graph.h"

struct Graph
{
    Vertex **vertexes;
    bool **edges;
    int size;    
};

struct Vertex
{
    int value;
    char component;
    bool visited;
};

Vertex *createVertex(int value)
{
    Vertex *vertex = new Vertex;
    vertex->value = value;
    vertex->component = '\0';
    vertex->visited = false;

    return vertex;
}

Graph *createGraph(int size)
{
    Graph *graph = new Graph;
    Vertex **vertexes = new Vertex*[size];
    bool **edges = new bool*[size];    
    for (int i = 0; i < size; i++)
    {
        edges[i] = new bool[size];
        for (int j = 0; j < size; j++)
            edges[i][j] = false;
        vertexes[i] = createVertex(0);
    }
    graph->vertexes = vertexes;
    graph->edges = edges;
    graph->size = size;

    return graph;
}

Graph *createGraph()
{
    return createGraph(1);
}

void addEdge(Graph *graph, int vertex1, int vertex2)
{
    graph->edges[vertex1][vertex2] = true;
    graph->edges[vertex2][vertex1] = true;
}

void addEdgeDirected(Graph *graph, int vertex1, int vertex2)
{
    graph->edges[vertex1][vertex2] = true;
}

void removeEdge(Graph *graph, int vertex1, int vertex2)
{
    graph->edges[vertex1][vertex2] = false;
    graph->edges[vertex2][vertex1] = false;
}

void removeEdgeDirected(Graph *graph, int vertex1, int vertex2)
{
    graph->edges[vertex1][vertex2] = false;
}

void findVertexesInComponent(Graph *graph, int vertex, char &letter)
{
    graph->vertexes[vertex]->component = letter;
    graph->vertexes[vertex]->visited = true;
    for (int i = 0; i < graph->size; i++)
        if (graph->edges[vertex][i] && !graph->vertexes[i]->visited)
            findVertexesInComponent(graph, i, letter);
}

void findComponents(Graph *graph)
{
    char letter = 'a';
    for (int i = 0; i < graph->size; i++)
        if (!graph->vertexes[i]->visited)
        {
            findVertexesInComponent(graph, i, letter);
            letter++;
        }
}

void printComponents(Graph *graph)
{
    int vertexesListed = 0;
    for (char i = 'a'; vertexesListed < graph->size; i++)
    {
        std::cout << "component " << i << ": ";
        for (int j = 0; j < graph->size; j++)
            if (graph->vertexes[j]->component == i)
            {
                std::cout << j << " ";
                vertexesListed++;
            }
        std::cout << "\n";
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
