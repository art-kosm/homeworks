#pragma once

struct Graph;
struct Vertex;

Graph *createGraph();
Graph *createGraph(int size);
void addEdge(Graph *graph, int vertex1, int vertex2);
void addEdgeDirected(Graph *graph, int vertex1, int vertex2);
void removeEdge(Graph *graph, int vertex1, int vertex2);
void removeEdgeDirected(Graph *graph, int vertex1, int vertex2);
void findComponents(Graph *graph);
void printComponents(Graph *graph);
void deleteGraph(Graph *graph);
