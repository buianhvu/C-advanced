#include<stdio.h>
#include<stdlib.h>

void quicksort(int a[], int l, int r)
{
  int i, j;
  int q, p;
  i = l - 1;
  j = r;
  p = l - 1;
  q = r;
  while(1){
    while(a[i++] <= a[r]);
    while(a[j--] <= a[r]);
    if(i >= j)
      break;
    exchange(a, i, j);
    if(a[i] == a[r])
      exchange(a, p++, i);
    if(a[j] == a[r])
      exchange(a, q--, j);
  }
  exchange(a, i, r);
  j = i + 1;
  i = i - 1;
  int k;
  for(k = l; k<= p; k++)
    exchange(a, k, j--);
  for(k = i; k<= q; k++)
    exchange(a, k, i++);
} 
      
