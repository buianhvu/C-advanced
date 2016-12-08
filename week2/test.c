#include "jval.c"

main(){
  int i,d;
  jval a, b;
  jval c[10];
  a = new_jval_i(10);
  b = new_jval_f(10.2);

  printf("This is printing section  \n");
  printf("%d %f \n", jval_i(a), b.f);
  printf("enter 5 inputs for array \n");
  for(i = 0; i < 5; i++)
    {
      scanf("%d", &d);
      c[i] = new_jval_i(d);
    }
  printf("p:0 \n");
  printf("%d", jval_i(c[2]));
  printf("before sorting \n");
  for(i = 0; i<5; i++)
    {
      printf("%d", jval_i( c[i] ));
      printf("\n");
    }
  sort_gen_i(c, 0, 4);
  printf("after sorting \n");
  for(i = 0; i<5; i++)
    printf("%d  ", jval_i(c[i]));
  printf("search location of member has value ? \n");
  scanf("%d", &d);
  a.i = d;
  int res;
  res = search_gen_i(c, 0, 4, a);
  if(res != 0)
    printf("Found m = %d", res);
  else
    printf("Not found \n");

  

  return 0;
}
