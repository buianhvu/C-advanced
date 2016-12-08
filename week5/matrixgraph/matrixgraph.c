#include "matrixgraph.h"

Graph creatGraph(int size) {
  Graph new;
  new.matrix = (int*) malloc(sizeof(int)*size*size);
  new.sizemax = size;
  return new;
}
void addEdge(Graph graph, int v1, int v2){
  int sizemax = graph.sizemax;
  if(v1 > sizemax - 1 || v2 > sizemax - 1)
    printf("Error \n");
  else
    {
      graph.matrix[v1*sizemax + v2 - 1] = 1;
      graph.matrix[v2*sizemax + v1 - 1] = 1;
    }
}
int adjacent(Graph graph, int v1, int v2)
{
 int sizemax = graph.sizemax;
  if(graph.matrix == NULL)
    return 0;
  if(graph.matrix[v1*sizemax + v2 - 1] == 1 && 
     graph.matrix[v2*sizemax + v1 - 1] == 1 )
    return 1;
  else
    return 0;
}


int getAdjacentVertices(Graph graph, int vertex, int *output)
{
  int j = 0;
  int sizemax = graph.sizemax;
  int i;
  if(graph.matrix == NULL)
    return 0;

  for(i = 0; i< sizemax; i++)
    {
      if( i == vertex)
	continue;
      if(adjacent(graph, vertex, i) == 1)
	{
	  output[j] = i;
	  j++;
	}
    }
  return j;
}
   
void dropGraph(Graph graph)
{
  free(graph.matrix);
}
