#include<stdio.h>
#include "rbgraph.h"

Graph creatGraph()
{
  return make_jrb();
}

void addEdge(Graph graph, int v1, int v2)
//this applied to directed graph(v1 -> v2)
{
  JRB find;
  find = jrb_find_int(graph, v1);
  if(find == NULL)
    {
      Graph tree;
      tree = make_jrb();
      jrb_insert_int(graph, v1, new_jval_v(tree));
      jrb_insert_int(tree, v2, new_jval_i(1));
    }
  else
    {
      Graph tree;
      tree = make_jrb();
      tree = (JRB) jval_v(find->val);
      jrb_insert_int(tree, v2, new_jval_i(1));
    }
}

int getAdjacentVertices(Graph graph, int vertex, int *output)
{
  JRB find;
  find = jrb_find_int(graph, vertex);
  if(find == NULL)
    {
    printf("Not found for vertex-%d\n", vertex);
    return 0;
    }
  else
    {
      JRB tree;
      tree = (JRB) jval_v(find->val);
      int total = 0;
      for(find = jrb_first(tree); find != jrb_nil(tree); find = jrb_next(find))
	{
	  output[total] = jval_i(find->key);
	  total++;
	}
      return total;
    }
}

void dropGraph(Graph graph)
{
  Graph find;
    for(find = jrb_first(graph); find != jrb_nil(graph); find = jrb_next(find))
    jrb_delete_node(find);
}

void BFS(Graph graph, int start, int stop, void (*func)(int))
{
  typedef struct {
    int vertex;
    int mark;
  }IsMarked;

  Queue queue;
  int output[];
  int num = 0;
  int i;
  queue = new_Queue();
  JRB find = jrb_find_int(graph, s);
  JRB p;
  for(p = jrb_first(s); p != jrb_nil(s); p = jrb_next(s))
    {
      Arr[i].mark = 0; 
      Arr[i].vertex = jval_i(p->val);
    }
  
  Enqueue(queue, s);
  mark[s] = 1;
  int n =  getAdjacentVertieces(graph, s, &output);
  for( i = 0; i<n; i++)
    {
      Enqueue(Queue, output[i]);
    }
  

