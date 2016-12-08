#include "directedgraph.h"
#include <stdlib.h>

Graph creatGraph()
{
	Graph new;
	new.vertices = make_jrb();
	new.edges = make_jrb();
	return new;
}

void addVertex(Graph graph, int id, char *name)
{

	JRB tree;
	JRB found = jrb_find_int(graph.vertices, id);
	if(found != NULL)
	{
		printf("The vertex has existed already");
		exit(1);
	}
	else
	{
		jrb_insert_int(graph.vertices, id, new_jval_s(name));
		jrb_insert_int(graph.edges, id, new_jval_v(tree));
	}

}

char* getVertex(Graph graph, int id)
{
	char *s = (char*) malloc(sizeof(char)*30);
	JRB p = jrb_find_int(graph.vertices, id);
	if(p == NULL)
	{
		printf("Not found vertices for id %d", id);
		return NULL;
	}
	else
	{
		return jval_s(p->val);
	}
}

void addEdge(Graph graph, int v1, int v2)
{
	JRB found1;
	JRB found2;
	found1 = jrb_find_int(graph.vertices, v1);
	if(found1 == NULL)
	{
		printf("Not found vertices %d\n", v1 );
		return;
	}
	found2 = jrb_find_int(graph.vertices, v2);
	if(found2 == NULL)
	{
		printf("Not found vertices %d\n", v2);
		return;
	}
	JRB p;
	p = jrb_find_int(graph.edges, v1);
	JRB tree;
	tree = (JRB) jval_v(p->val);
	jrb_insert_int(tree, v2, new_jval_i(1));
}

int hasEdge(Graph graph, int v1, int v2)
{
	JRB p;
	p = jrb_find_int(graph.edges, v1);
	JRB tree;
	tree = (JRB) jval_v(p->val);
	JRB found;
	found = jrb_find_int(tree, v2);
	if(found != NULL)
		return 1;
	else
		return 0;

}

int *indegree(Graph graph, int v1, int *output)
{
	

}