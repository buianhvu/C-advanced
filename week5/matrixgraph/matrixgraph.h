#include<stdio.h>
#include<stdlib.h>
typedef struct {
  int *matrix;
  int sizemax;
}Graph;

Graph creatGraph(int size);
void addEdge(Graph graph, int v1, int v2);
int getAdjacentVertices(Graph graph, int vertex, int *output);
void dropGraph(Graph graph);

