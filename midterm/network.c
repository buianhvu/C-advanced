#include "rbgraph.h"
#include <string.h>
#include <stdlib.h>


typedef struct {
  char name[30];
}person;

typedef struct {
  person *list;
  int num;
  Graph graph;
}network;

network inputFile();
void findAdjacent(network net1, char name[]);
void findfriendnumber(network net1);
void findmutual(network net1, char name[]);


int main() 
{int i;
  int choice;
  network net;
  net.list = (person*) malloc(100*sizeof(person));
  net.num =  0;
  net.graph = creatGraph();
  char name[20];
  char name1[20];
  do
    {
    printf("**********MENU**********\n");
    printf("1. Input from file, print number of vertices \n");
    printf("2. List friends of: \n");
    printf("3. List of number friends \n");
    printf("4. Find mutual friends \n");
    printf("5. Exit \n");
    scanf("%d", &choice);
    switch(choice)
      {
      case 1:
	net = inputFile();
	printf("Number of vertices: %d \n", net.num+1);
       	break;
      case 2:
	printf("Enter name \n");
	printf("Notice that name put between the parathenses \n");
	while(getchar() != '\n');
	scanf("%[^\n]", name);
	findAdjacent(net, name);
	break;
      case 3:
	findfriendnumber(net);
	break;
      case 4:
	printf("Enter a name \n");
	while(getchar() != '\n');
	scanf("%[^\n]", name1);
	findmutual(net, name1);
	break;
      case 5:
	break;
      default:
      break;
      }
    }while(choice != 5);
  return 0;
}
	     
network inputFile()
{
  int i,j;
  int found, found1;
  char str[150];
  char *token = (char*) malloc(sizeof(char)*20);
  int number;
  FILE *f1;
  f1 = fopen("data2.txt", "r");
  if(f1 == NULL)
    {
      printf("Can't open file \n");
      return;
    }
  network net1;
  net1.list = (person*) malloc(sizeof(person)*100);
  net1.graph = creatGraph();
  net1.num = 0;
  fscanf(f1, "%d\n", &number);



  int v1, v2;
  for(j = 0; j<= number-1; j++)
    {
      fgets(str,100, f1);
      token = strtok(str, " ");
      found = 0;
      found1 = 0;
      //check xem ban1 co trong list chua
      for(i = 0; i <= net1.num; i++)
	{
	  if(strcmp( token, net1.list[i].name) == 0)
	    {
	      found = 1;
	      v1 = i;
	    }
	}
      if(found == 0)
	{
	  strcpy(net1.list[net1.num].name,token);
	  v1 = net1.num;
	  net1.num = net1.num + 1;
	}
      token = strtok(NULL, " ");
      //check ban so 2
      for(i = 0; i<=net1.num; i++)
	{
	  if(strcmp(token, net1.list[i].name) == 0)
	    {
	      found1 = 1;
	      v2 = i;
	    }
	}
      if(found1 == 0)
	{	  
	  strcpy(net1.list[net1.num].name,token);
	  v2 = net1.num;
	  net1.num = net1.num + 1;
	}
      addEdge(net1.graph, v1, v2);
      addEdge(net1.graph, v2, v1);
    } 
  fclose(f1);
  return net1;
}

void findAdjacent(network net1, char name[])
{
  int *output = (int*) malloc(sizeof(int)*20);
  int i;
  int found = 0;
  int num;
  int n;
  for(i = 0; i <= net1.num; i++)
    {
      if(strcmp(net1.list[i].name, name) == 0)
	{
	  found = 1;
	  break;
	}
    }

  if(found == 0)
    {
      printf("Not found that one \n");
      return;
    }
  JRB node = make_jrb();
  JRB ptr = make_jrb();
  JRB tree = make_jrb();
  node = jrb_find_int(net1.graph, i);
  tree = (JRB) jval_v(node->val);


  for(ptr = jrb_first(tree); ptr != jrb_nil(tree); ptr = jrb_next(ptr))
    {
      printf("%-30s \n",net1.list[ jval_i(ptr->key)].name);
    }
}

 void findfriendnumber(network net1)
{
  int *output = (int*) malloc(sizeof(int)*20);
  int i, j;
  int Max = getAdjacentVertices(net1.graph, 0, output);
  int num;
  int n;
  for(i =0; i<net1.num; i++)
    {
      if(Max < getAdjacentVertices(net1.graph, i, output))
	{
	  Max = getAdjacentVertices(net1.graph, i, output);
	}
    }
  for(j=1; j<=Max; j++)
    {
      printf("%d. ", j);
      for(i=0; i<=net1.num; i++)
	{
	  if(j == getAdjacentVertices(net1.graph, i, output) ) 
	    {
	      printf("%-s ", net1.list[i].name);
	    }
	}
      printf("\n");
    }
}

void findmutual(network net1, char name[])
{
int *output = (int*) malloc(sizeof(int)*20);
  int i;
  int found = 0;
  int num;
  int n;
  for(i =0; i<net1.num; i++)
    {
      if(strcmp(name, net1.list[i].name) == 0)
	{	
	  n = i;
	  found = 1;
	}
    }
  if(found == 0)
    {
      printf("Failed enter name \n");
      return;
    }

  JRB node = make_jrb();
  JRB ptr = make_jrb();
  JRB tree = make_jrb();
  node = jrb_find_int(net1.graph, i);
  JRB ptr1 = make_jrb();

  for(ptr = jrb_first(net1.graph); ptr != jrb_nil(net1.graph); ptr = jrb_next(ptr))
    {
      tree = (JRB) jval_v(ptr->val);
      for(ptr1 = jrb_first(tree); ptr1 != jrb_nil(tree); ptr1 = jrb_next(ptr1))
	if(jval_i(ptr1->key) == n)
	  {
	    printf("%s ", net1.list[jval_i(ptr->key)].name);
	  }
    }
  printf("\n");
}
