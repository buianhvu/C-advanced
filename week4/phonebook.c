#include "jval.h"
#include "jrb.h"
#include<stdio.h>
#include<string.h>
typedef struct
{
  char name[30];
  long num;
}person;
void getData(char filename[], JRB *book, int size);

main()
{
  char search[30];
  int i,choice;
  JRB book;
  do {
    printf("MENU \n");
    printf("1. Creat phone book \n");
    printf("2. Input from file \n");
    printf("3. Insert person \n");
    printf("4. Delete person \n");
    printf("5. Traversal \n");
    printf("6. Exit \n");
    scanf("%d", &choice);

    switch(choice)
      {
      case 1:
	printf("Creat phone book \n");
	book = make_jrb();
	printf("Done \n");
	break;
      case 2:
	printf("Input from file \n");
	getData("input.txt", &book, 5);
	break;
      case 3:
	printf("Insert person \n");
	person temp;
	printf("Enter name \n");
	scanf("%s", temp.name);
	printf("Enter number \n");
	scanf("%ld", &temp.num);
	jrb_insert_str(book, strdup(temp.name), new_jval_l(temp.num));
	break;
      case 4:
	printf("Enter a name to delete\n");
	scanf("%s", search);
	JRB result;
	result = jrb_find_str(book, search);
	if(result != NULL)
	  {
	    jrb_delete_node(result);
	    break;
	  }
	else
	  printf("not found \n");
	break;
      case 5:
	printf("Printing list :\n");
	JRB ptr;
       for(ptr = jrb_first(book); ptr != jrb_nil(book); ptr = jrb_next(ptr))
	 {
	   printf("%-15s : %ld \n",jval_s(ptr->key), jval_l(ptr->val));
	 }
    
	break;
      case 6:
	printf("End of using \n");
	printf("Exit \n");
      default:
	printf("Enter menu again \n");
	break;
      }
  } while(choice != 6 );
}


void getData(char filename[], JRB *book, int size)
{
  int i;
  FILE *f1;
  person temp;
  f1 = fopen(filename, "r");
  for(i = 0; i < size; i++)
    {
      fscanf(f1, "%s%ld\n", temp.name, &temp.num);
      jrb_insert_str(*book, strdup(temp.name), new_jval_l(temp.num) );
    }
  fclose(f1);
};
