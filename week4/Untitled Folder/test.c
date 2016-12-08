#include "jrb.h"
#include "jval.h"
#include<stdio.h>

#define MAX 100
main()
{
  int i, rd;
  JRB tree = make_jrb();
  JRB result = make_jrb();
  Jval arr[MAX];   
  for(i = 0; i<MAX; i++) 
    {
      rd = rand()%100; 
      arr[i] = new_jval_i(rd); 
      jrb_insert_int(tree, i, arr[i]); 
    } 
  int d;
  printf("type in the key to find\n");
  scanf("%d", &d); 
  result = jrb_find_int(tree, d);
  if(result == NULL)
    printf("not found \n");
  else
    printf("found!\n");
  return 0;
}
