#include "matrixgraph.h"
#include<stdio.h>
main()
{
int choice, v1, v2, size,i;
int output2[100];
Graph graph;
 int num;

  do{
    printf("1. Creat graph \n");
    printf("2. Add Egde \n");
    printf("3. Get Adjacent Vertices \n");
    printf("4. Drop the graph \n");
    scanf("%d", &choice);
    switch(choice)
      {
      case 1:
	printf("Enter size \n");
	scanf("%d", &size);
	graph = creatGraph(size);
	printf("Done !\n");
	break;
      case 2:
	printf("Enter two vertices to make edge \n");
	printf("V1 = ");
	scanf("%d", &v1);
	printf("\nV2 = ");
	scanf("%d", &v2);
	printf("\n");
	addEdge(graph, v1, v2);
	printf("Done !\n");
	break;
      case 3:
	printf("Enter the vertex \n");
	scanf("%d", &v1);
	num = getAdjacentVertices(graph, v1, output2);
	if(num == 0)
	  printf("no adjacent vertices \n");
	else
	  {
	    printf("Adjacent vertices: \n");
	    for(i = 0; i < num; i++)
	      {
		printf("%d ", output2[i]);
	      }
	    printf("\n");
	  }
	break;
      case 4:
	dropGraph(graph);
	break;
      default:
	printf("Enter choice again \n");
	break;
      }
  }while(choice != 4);
}
