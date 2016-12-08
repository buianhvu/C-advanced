#include<stdio.h>
#include "jval.h"

void exchange(jval a[], int i, int j)
{
  jval b;
  b = a[i];
  a[i] = a[j];
  a[j] = b;
}
      

void quicksort_i(jval a[], int l, int r)
{
  if(r <= l)
    return;
  int i = l - 1, j = r;
  int p = l - 1, q = r;
  int k;
  while(1)
    {
      while( jval_i( a[++i]) < jval_i(a[r]) );
      while( jval_i( a[--j]) > jval_i(a[r]) )
	if(j==l) 
	  break;
      if(i >= j )
	break;
      exchange( a, i, j );
      if( jval_i(a[i]) == jval_i(a[r]) );
      exchange( a, ++p, i);
      if( jval_i(a[j]) == jval_i(a[r]) );
      exchange( a, --q, j);
    }
  exchange(a, i, r);
  j = i - 1;
  i = i + 1;
  for( k = l; k <= p; k++)
    {
      exchange(a, k, j--);
    }
  for(k = r-1; k >= q; k--)
    {
      exchange(a, k, i++);
    }
  quicksort_i(a, l, j);
  quicksort_i(a, i, r);
}

main()
{
  int i;
  jval a[15];

  printf("test 1 \n");
  jval c[2];
  c[0] = new_jval_i(1);
  c[1] = new_jval_i(2);
  exchange(c, 0, 1);
  printf("%d \n \n", jval_i(c[0]) );



  for(i = 0; i<= 14; i++)
    {
      a[i] = new_jval_i(rand()%10);
    }
  printf("before sorting \n");
  for(i = 0; i<= 14; i++)
    {
      printf("%d  ", jval_i(a[i]) );
    }
  printf("\n");

  quicksort_i(a, 0, 14);

  for(i = 0; i<= 14; i++)
    {
      printf("%d  ", jval_i(a[i]) );
    }
  return 0;
}
