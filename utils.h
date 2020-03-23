#include <stdlib.h>
#include <stdio.h>

void printarray(int *a, size_t size, char *name)
{
  printf("%s : [", name);
  for(size_t i = 0; i < size-1; i++) {
    printf(" %i,", a[i]);
  }
  printf(" %i]\n", a[size-1]);
}