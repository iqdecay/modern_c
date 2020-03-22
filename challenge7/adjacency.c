#include <stdlib.h>
#include "adjacency.h"


adjaMatrix *init_adja(size_t size)
{
  adjaMatrix *a = malloc(sizeof(adjaMatrix *));
  int *values = calloc(size * size, sizeof(int));
  int **rows = malloc(size * sizeof(int *));
  for (size_t i = 0; i < size; ++i) {
    rows[i] = values + i * size;
  }
  a->matrix = rows;
  a->size = size;
  return a;
}

int add_link(adjaMatrix *m, int node1, int node2, int value)
{
  if (node1 >= m->size || node2 >= m->size) return 0;
  // An adjacency matrix is symetrical when the graph is undirected
  m->matrix[node1][node2] = value;
  m->matrix[node2][node1] = value;
  return 1;
}

int get_link(adjaMatrix *m, int node1, int node2)
{
  if (node1 >= m->size || node2 >= m->size) return 0;
  return m->matrix[node1][node2];
}
