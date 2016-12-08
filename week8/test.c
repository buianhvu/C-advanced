#include "directedgraph.h"

main()
{
  Graph g;
  g = creatGraph();
  addVertex(g, 0, "V0");
  addVertex(g, 1, "V1");
  addVertex(g, 2, "V2");
  addVertex(g, 3, "V3");
  addEdge(g, 0, 1);
  addEdge(g, 1, 2);
  addEdge(g, 2, 0);
  addEdge(g, 1, 3);
}
