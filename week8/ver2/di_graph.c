#include "directedgraph.h"

Graph creatGraph() {
  Graph new;
  new.edges = make_jrb();
  new.vertices = make_jrb();
  return new;
}

void addVertex(Graph graph, int id, char *name)
{
  Jval val;
  JRB tree;
  val = new_jval_s(name);
  jrb_insert_int(graph.vertices, id, val);
  jrb_insert_int(graph.edges, id, new_jval_v(tree));
}

char* getVertex(Graph graph, int id)
{
  JRB find;
  JRB found;
  found = jrb_find_int(graph.vertices, id);
  if(found == NULL)
    printf("Not found \n");
  else
    return jval_s(found->val);
}

void addEdge(Graph graph, int v1, int v2)
{
  JRB tree;
  JRB found1;
  found1 = jrb_find_int(graph.edges, v1);
  tree = (JRB) jval_v(found1->val);
  jrb_insert_int(tree, v2, new_jval_i(1));
}

int hasEdge(Graph graph, int v1, int v2)
{
  int found = 0;
  JRB tree1;
  JRB tree2;
  JRB found1;
  JRB found2;
 
  found1 = jrb_find_int(graph.edges, v1);
  tree1 = (JRB) jval_v(found1->val);
  if ( jrb_find_int(tree1, v2) != NULL)
    found = 1;
  found2 = jrb_find_int(graph.edges, v2);
  tree2 = (JRB) jval_v(found2->val);
  if ( jrb_find_int(tree2, v1) != NULL)
    found = 1;
  return found;
}
