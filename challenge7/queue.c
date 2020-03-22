//
// Created by lulwat on 21/03/2020.
//
#include <stdlib.h>
#include <string.h>

#include "queue.h"


queue *init_queue(size_t max_size)
{
  queue *q = malloc(sizeof(queue *));
  q->values = malloc(sizeof(int[max_size]));
  q->capacity = max_size;
  q->length = 0;
}

size_t length_queue(queue *q)
{
  return q->length;
}

size_t capacity_queue(queue *q)
{
  return q->capacity;
}

queue *add_queue(queue *q, int elt)
{
  size_t ocapacity = capacity_queue(q);
  size_t olength = length_queue(q);
  if (olength == ocapacity) {
    int *nvalues;
    nvalues = realloc(q->values, sizeof(int[2 * ocapacity]));
    if (!nvalues) {
      return 0;
    }
    nvalues[olength] = elt;
    *q = (queue) {
            .capacity = 2 * ocapacity,
            .values = nvalues,
            .length = olength + 1,
    };
  } else {
    q->values[olength] = elt;
    q->length += 1;
  }
  return q;

}

int pop_queue(queue *q)
{
  size_t olength = q->length;
  if (olength == 0) {
    return 0;
  } else {
    int r = q->values[0];
    memcpy(q->values, q->values + 1, sizeof(int[olength - 1]));
    q->length-= 1;
    return r;
  }
}

