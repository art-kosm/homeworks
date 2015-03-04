#pragma once

struct Graph;
struct Vertex;

Graph *createGraph(int size);
void addEdge(Graph *graph, int vertex1, int vertex2, int length);
void usePrimsAlgorithm(Graph *graph);
void deleteGraph(Graph *graph);
