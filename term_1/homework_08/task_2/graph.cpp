#include <iostream>
#include <limits>
#include "graph.h"

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

void quicksort(int array[], int left, int right)
{
    if (left < right)
    {
        int pivotIndex = (left + right) / 2;
        int pivotValue = array[pivotIndex];
        std::swap(array[pivotIndex], array[right]);
        int storeIndex = left;
        for (int i = left; i < right; i++)
            if (array[i] < pivotValue)
            {
                std::swap(array[i], array[storeIndex]);
                storeIndex++;
            }
        std::swap(array[storeIndex], array[right]);

        quicksort(array, left, storeIndex - 1);
        quicksort(array, storeIndex + 1, right);
    }
}

void sortVertexes(Graph *graph)
{
    int size = graph->size;
    int *distances = new int[size];
    for (int i = 0; i < size; i++)
        distances[i] = graph->vertexes[i]->distance;

    quicksort(distances, 0, size - 1);

    int position = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (i == 0 || (distances[i] != distances[i - 1]))
                if (graph->vertexes[j]->distance == distances[i])
                {
                    graph->vertexes[j]->position = position;
                    position++;
                }
}

void useDijkstrasAlgorithm(Graph *graph, int start)
{
    graph->vertexes[start]->distance = 0;
    for (int j = 0; j < graph->size; j++)
    {
        int minVertex = -1;
        int min = std::numeric_limits<int>::max();
        for (int i = 0; i < graph->size; i++)
            if (!graph->vertexes[i]->visited && graph->vertexes[i]->distance < min)
            {
                min = graph->vertexes[i]->distance;
                minVertex = i;
            }

        for (int i = 0; i < graph->size; i++)
            if (!graph->vertexes[i]->visited && graph->edges[minVertex][i] >= 0)
            {
                int newDistance = graph->vertexes[minVertex]->distance + graph->edges[minVertex][i];
                if (newDistance < graph->vertexes[i]->distance)
                {
                    graph->vertexes[i]->distance = newDistance;
                    graph->vertexes[i]->previous = minVertex;
                }
            }

        graph->vertexes[minVertex]->visited = true;
    }

    sortVertexes(graph);
}

void showCity(Graph *graph, int position)
{
    for (int i = 0; i < graph->size; i++)
        if (graph->vertexes[i]->position == position)
        {
            Vertex *current = graph->vertexes[i];
            std::cout << "city: " << i + 1 << ", distance: " << current->distance << ", way: " << i + 1 << " ";
            while (current != nullptr)
            {
                int previous = current->previous;
                if (previous >= 0)
                {
                    std::cout << previous + 1 << " ";
                    current = graph->vertexes[previous];
                }
                else
                {
                    std::cout << "\n";
                    current = nullptr;
                }
            }
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
