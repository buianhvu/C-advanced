#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
  char *str;
  char *str1;
  char c;
  str = (char*) malloc(100*sizeof(char));
  str1 = (char*)malloc(100*sizeof(char));
  printf("input a string \n");
  scanf("%[^\n]",str);
  str1 = strtok(str, "cut");
  printf("%s", str1);
  printf("continue cutting \n");
  str1 = strtok(NULL, "cut");
  printf("\n%s", str1);
  printf("FILE INput test \n");
  FILE *f1;
  f1 = fopen("stringtest.txt", "r");
  fscanf(f1, "mon%*d=%[^\n]\n",str);
  printf("last print: %s", str);
  fclose(f1);
}
