#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "prioq.h"

prioq *init_prioq(size_t max_size)
{
  prioq *pq = malloc(sizeof(prioq *));
  pq->values = malloc(sizeof(int[max_size]));
  pq->priorities = malloc(sizeof(int[max_size]));
  pq->length = 0;
  pq->capacity = max_size;
}

size_t length_prioq(prioq *pq)
{
  return pq->length;
}

size_t capacity_prioq(prioq *pq)
{
  return pq->capacity;
}

prioq *add_prioq(prioq *pq, int elt, int prio)
{
  size_t ocapacity = capacity_prioq(pq);
  size_t olength = length_prioq(pq);
  size_t nlength = olength + 1;
  pq->length = nlength;
  if (olength == ocapacity) {
    int *nvalues, *npriorities;
    int ncapacity = 2 * ocapacity;
    nvalues = realloc(pq->values, sizeof(int[ncapacity]));
    if (!nvalues) {
      return 0;
    }
    npriorities = realloc(pq->priorities, sizeof(int[ncapacity]));
    if (!npriorities) {
      return 0;
    }
    *pq = (prioq) {
            .capacity = ncapacity,
            .priorities = npriorities,
            .values = nvalues,
            .length = nlength,
    };
  }
  size_t i = 0;
  while (prio > pq->priorities[i] && i < olength) {
    i++;
  }
  memcpy(pq->values + i + 1, pq->values + i, sizeof(int[olength - i]));
  memcpy(pq->priorities + i + 1, pq->priorities + i, sizeof(int[olength - i]));
  pq->values[i] = elt;
  pq->priorities[i] = prio;
  return pq;
}

int pop_prioq(prioq *pq)
{
  size_t olength = pq->length;
  if (olength == 0) {
    return 0;
  } else {
    int r = pq->values[0];
    memcpy(pq->values, pq->values + 1, sizeof(int[olength - 1]));
    memcpy(pq->priorities, pq->priorities + 1, sizeof(int[olength - 1]));
    pq->length -= 1;
    return r;
  }
}



//int main(void){
//  prioq * pq = init_prioq(10);
//
//  add_prioq(pq, 11, 10);
//  add_prioq(pq, 13, 9);
//  add_prioq(pq, 15, 5);
//  add_prioq(pq, 17, 8);
//  add_prioq(pq, 19, 12);
//  printf("%i\n", pop_prioq(pq));
//  printf("%i\n", pop_prioq(pq));
//  printf("%i\n", pop_prioq(pq));
//  printf("%i\n", pop_prioq(pq));
//  printf("%i\n", pop_prioq(pq));
//}
