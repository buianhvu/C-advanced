#include<stdio.h>
#include<string.h>

void* memcpy1(void* region1, const void* region2, size_t n)
{
  const char* first = (const char*) region2;
  const char* last = ((const char*) region2) + n;
  char* result = (char*) region1;
  while(first != last)
    *result++ = *first++;
  return result;
}

main()
{
  char s1[20];
  char s2[20];
  char *s3;
  printf("Input for s1 \n");
  gets(s1);
  printf("Input for s2 \n");
  gets(s2);
  printf("mencpy s1 & s2 \n");
  s3 = memcpy1(s1, s2, strlen(s2)*sizeof(char));
  printf("output : %s \n", s3);

  return 0;
}
