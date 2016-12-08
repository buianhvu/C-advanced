#include<stdio.h>
#include "jrb.h"
#include "jval.h"
#include "queue_lib.h"
typedef JRB Graph;
Graph creatGraph();
void addEdge(Graph graph, int v1, int v2);
int getAdjacentVertices(Graph graph, int vertex, int *output);
void dropGraph(Graph graph);
void BFS(Graph graph, int start, int stop, void (*func)(int));
