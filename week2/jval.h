#include<stdio.h>
typedef union {
  int i;
  float f;
  double d;
  char c;
  void *v;
  char *s;
}Jval_U;

typedef Jval_U jval;

jval new_jval_i(int i);
jval new_jval_f(float j);
int jval_i(jval a);
float jval_f(jval a);
void sort_gen(jval *arr, int l, int r, int (*comspare)(jval*, jval*));
void sort_gen_i(jval *arr, int l, int r);
int search_gen_i(jval *arr, int l, int r, jval val);
