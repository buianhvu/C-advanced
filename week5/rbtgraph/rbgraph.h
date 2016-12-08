#include<stdio.h>
#include "jrb.h"
#include "jval.h"
typedef JRB Graph;
Graph creatGraph();
void addEdge(Graph graph, int v1, int v2);
int getAdjacentVertices(Graph graph, int vertex, int *output);
void dropGraph(Graph graph);
