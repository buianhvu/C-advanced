#include "rbgraph.h"

main()
{
  Graph graph;
  int v1, v2, choice; 
  int i, n;
  int output[50];
  do
  {
    printf("MENU \n");
    printf("1. Creat Graph \n");
    printf("2. Add Edge (directed) \n");
    printf("3. Get Adjacent Vertices \n");
    printf("4. Drop Graph And Exit \n");
    printf("*Enter choice*  ");
    scanf("%d", &choice);
    switch(choice)
      {
      case 1:
	graph = creatGraph();
	printf("Done ! \n");
	break;
      case 2:
	printf("Enter two vertices v1 and v2 (v1 to v2) \n");
	printf("V1: ");
	scanf("%d", &v1);
	printf("V2: ");
	scanf("%d", &v2);
       	addEdge(graph, v1, v2);
	break;
      case 3:
	printf("Enter the vertex \n");
	scanf("%d", &v1);
	n = getAdjacentVertices(graph, v1, output);
	if(n != 0)
	  {
	    printf("V%d's list of adjacent vertices \n", v1);
	    for(i = 0; i < n; i++)
	      {
		printf("%d  ", output[i]);
	      }
	    printf("\n");
	  }
	break;
      case 4:
	if(graph == NULL)
	  break;
	dropGraph(graph);
	printf("Dropped \n");
	printf("Exit now \n");
	break;
      default:
	printf("Enter choice again \n");
	break;
      }
  }while(choice != 4);
}
