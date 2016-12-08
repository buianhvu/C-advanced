#include<stdio.h>
#include "jval.h"
jval new_jval_i(int i){
  jval new;
  new.i = i;
  return new;
}

jval new_jval_f(float f){
  jval new;
  new.f = f;
  return new;
}

jval new_jval_s(char *s){
  jval new;
  new.s = s;
  return new;
}

int jval_i(jval a)
{
  int i = a.i;
  return i;
}

float jval_f(jval a)
{
  float f = a.f;
  return f;
}

void sort_gen(jval *arr, int l, int r, int (*compare)( jval*, jval* ) )
{
  if(l >= r)
    return;
  int i, p, j, q;
  int k;
  i =  l - 1;
  p = i;
  j = r;
  q = j;
  while(1)
    {
      while(compare(&arr[r] , &arr[++i]) > 0);
      while(compare(&arr[r] , &arr[--j]) < 0)
	if(j == l)
	  break;
      if(i >= j)
	break;
      exchange(&arr[i], &arr[j]);
      if(compare(&arr[i], &arr[r]) == 0)
	exchange(&arr[i], &arr[++p]);
      if(compare(&arr[j], &arr[r]) == 0)
	exchange(&arr[j], &arr[--q]);
    }
  exchange(&arr[i], &arr[r]);
  j = i - 1;
  i = i + 1;
  for(k = l; k <= p; k++)
    exchange(&arr[k], &arr[j--]);
  for(k = r - 1; k >= q; k--)
    exchange(&arr[k], &arr[i++]);

  sort_gen(arr, l, j, compare);
  sort_gen(arr, i, r, compare);
}

int search_gen(jval* arr, int l, int r, jval val, int (*compare)(jval*, jval*) )
{
  if(l > r)
    return 0;
  int m = (l + r)/2;
  if(compare(&arr[m], &val) == 0)
    return m;
  else if(compare(&arr[m], &val) == 1)
    return search_gen(arr, l, m - 1, val, compare);
  else
    return search_gen(arr, m + 1, r, val, compare);
}



int exchange(jval* a, jval *b)
{
  jval temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int compare_i(jval *a, jval *b)
{
  if((*a).i > (*b).i )
    return 1;
  else if((*a).i < (*b).i)
    return -1;
  else
    return 0;
}

void sort_gen_i(jval *arr, int l, int r)
{
  sort_gen(arr, l, r, &compare_i);
}
	     
int search_gen_i(jval *arr, int l, int r, jval val)
{
  search_gen(arr, l , r, val, &compare_i);
}
