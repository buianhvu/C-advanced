#include "rbgraph.h"
#include <string.h>
#include <stdlib.h>

typedef struct 
{
  char name[20];
}station;

typedef struct
{
  station *list;
  int num;
  Graph graph;
}map;

map inputFile();
void findAdjacent(map mapfile, char name[]);

int main()
{
  map mapfile;
  mapfile.graph = creatGraph();
  mapfile.list = (station*) malloc(sizeof(station)*20);
  mapfile.num = 0;
  int choice;
  int i;
  char filename[20];
  char stationname[20];
do
  {
    printf("**********  MENU  ********** \n");
    printf("1. Input from file \n");
    printf("2. List all stations \n");
    printf("3. Find adjacent staions of \n");
    printf("4. Exit\n");
    scanf("%d", &choice);
    switch(choice)
      {
      case 1:
	mapfile = inputFile(filename);
	break;
      case 2:
	if(mapfile.num == 0)
	  printf("No stations in list \n");
	else
	  for(i=0; i<=mapfile.num; i++)
	    printf("%d. %-20s \n", i+1, mapfile.list[i].name);
	break;
      case 3:
	printf("Input a station name \n");
	while(getchar() != '\n');
	scanf("%[^\n]", stationname);
	findAdjacent(mapfile, stationname);
	break;
      case 4:
	break;
      default:
	printf("Enter choice again \n");
      }
  }while(choice != 4 );

 return 0;
}

map inputFile()
{
  int i;
  map outmap;
  int MAX = 10;
  char temp[50];
  FILE *f1;
  f1 = fopen("input.txt", "r");
  if(f1 == NULL)
    {
      printf("Invalid openning \n");
      return;
    }
  //Initialize map
  outmap.num = 0;
  outmap.list = (station*) malloc(sizeof(station)*20);
  outmap.graph = creatGraph();

  //get the word [STATIONS]
  while(1)
    {
      if( strcmp( fgets(temp, 100, f1), "[STATIONS]\n") == 0 );
      break;
    };
  for(i = 0; i< MAX ; i++)
    {
      fscanf(f1, "S%*d=%[^\n]\n", outmap.list[i].name);
      outmap.num++;
    };
  //get the word [LINES]
  while(1)
    {
      if( strcmp( fgets(temp, 100, f1), "[LINES]\n") == 0);
      break;
    };
  char *token;
  char c;
  int v1, v2;
  while(!feof(f1))
    {
      fscanf(f1, "M%*d=%[^\n]\n", temp);
      token = strtok(temp, " ");
      c = token[1];
      v1 = c - '0';
      token = strtok(NULL, " ");
      while( token != NULL ) 
	{
	  c = token[1];
	  v2 = c - '0';
	  addEdge(outmap.graph, v1 ,v2);
	  addEdge(outmap.graph, v2 ,v1);
	  v1 = v2;
	  token = strtok(NULL, " ");
	}
    }
  fclose(f1);
  return outmap;
}

void findAdjacent(map mapfile, char name[])
{
  int *output = (int*) malloc(sizeof(int)*20);
  int i;
  int found = 0;
  int num;
  int n;
  for(i = 0; i <= mapfile.num; i++)
    {
      if(strcmp(mapfile.list[i].name, name) == 0)
	{
	  found = 1;
	  break;
	}
    }

  if(found == 0)
    {
      printf("Not found \n");
      return;
    }
  printf("LIST OF ADJACENT STATIONS \n");
  JRB node = make_jrb();
  JRB ptr = make_jrb();
  JRB tree = make_jrb();
  node = jrb_find_int(mapfile.graph, i+1);
  tree = (JRB) jval_v(node->val);


  for(ptr = jrb_first(tree); ptr != jrb_nil(tree); ptr = jrb_next(ptr))
    {
      printf("%-30s \n",mapfile.list[ jval_i(ptr->key) - 1 ].name);
    }
}
