#pragma once

struct Graph;
struct Vertex;

Graph *createGraph(int size);
void addEdge(Graph *graph, int vertex1, int vertex2, int length);
void useDijkstrasAlgorithm(Graph *graph, int start);
void showCity(Graph *graph, int position);
void deleteGraph(Graph *graph);
