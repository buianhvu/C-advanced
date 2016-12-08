#include "jrb.h"
#include "jval.h"
#include<stdio.h>
typedef struct {
  JRB edges;
  JRB vertices;
}Graph;

Graph creatGraph();
void addVertex(Graph graph, int id, char *name);
char *getVertex(Graph graph, int id);
void addEdge(Graph graph, int v1, int v2);
int hasEdge(Graph graph, int v1, int v2);
int *indegree(Graph graph, int v1, int *output);
int *outdegree(Graph graph, int v1, int *output);
int DAG(Graph graph);
void dropGraph(Graph graph);
