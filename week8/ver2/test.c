#include <stdio.h>
#include "directedgraph.h"
#include <stdlib.h>

int main()
{
	Graph graph;
	int choice;
	int id;
	int id1;
	char name[30];
	char *get = (char*) malloc(sizeof(char)*35);
	do
	{
		printf("*****MENU*****\n");
		printf("1. Create graph\n");
		printf("2. Add vertex \n");
		printf("3. Get vertex \n");
		printf("4. Add Edge\n");
		printf("5. Has Edge\n");
		printf("6. Indegree\n");
		printf("7. Out degree\n");
		printf("8. DAG\n");
		printf("9. Drop graph\n");
		scanf("%d", &choice);
		switch(choice)	
		{	
		case 1:
			graph = creatGraph();
			printf("Done \n");
			break;
		case 2:
			printf("Enter name\n");
			scanf("%s", name);
			printf("Enter id \n");
			scanf("%d", &id);
			addVertex(graph, id, name);
			printf("Done \n");
			break;
		case 3:
			printf("Enter an id to get name\n");
			scanf("%d", &id);
			get = getVertex(graph, id);
			printf("%s \n", get);
			printf("Done\n");
			break;
		case 4:
			//Note that the edge pointed from 1st to 2st one
			printf("Enter the first id\n");
			scanf("%d",&id);
			printf("Enter the 2nd id\n");
			scanf("%d",&id1);
			addEdge(graph, id, id1);
			printf("Done\n");

			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		default:
			printf("Enter choice again \n");
		}
	}while(choice != 9); //end of do while

} //main
