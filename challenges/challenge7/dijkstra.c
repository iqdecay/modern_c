#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "utils.h"
#include "adjacency.h"
#include "queue.h"

int get_next(size_t size, int *visited, int *distances, int source)
{
  int min = INT_MAX;
  int next;
  for (size_t current = 0; current < size; current++) {
    if (!visited[current]) {
      if (distances[current] < min) {
        min = distances[current];
        next = current;
      }
    }
  }
  return next;
}


// Put in prev the node that has the shortest path from root
void djikstra(adjaMatrix *a, int source, int *prev)
{
  size_t size = a->size;
  int dist[size];
  // memset uses unsigned char, so the dist is set "by hand"
  for (size_t i = 0; i < size; i++) {
    dist[i] = INT_MAX;
  }
  dist[source] = 0;
  memset(prev, -1, size * sizeof(int));
  prev[source] = 0;
  int *visited = malloc(sizeof(int[size]));
  int unvisited = size;
  int current, distance, current_dist, new_dist;
  while (unvisited > 0) {
    current = get_next(size, visited, dist, source);
    visited[current] = 1;
    unvisited--;
    for (size_t i = 0; i < size; i++) {
      distance = get_link(a, current, i);
      new_dist = dist[current] + distance;
      current_dist = dist[i];
      if (distance > 0) {
        if (new_dist < current_dist) {
          dist[i] = new_dist;
          prev[i] = current;
        }
      }
    }
  }
}

queue *shortest_path(int *prev, int source, int target)
{
  queue *q = init_queue(sizeof(prev));
  int current;
  int previous = target;
  add_queue(q, target);
  while (previous != source) {
    current = previous;
    previous = prev[current];
    add_queue(q, previous);
  }
  reverse_queue(q);
  return q;
}


int main(void)
{
  int size = 5;
  adjaMatrix *a = init_adja(size);
  add_link(a, 0, 1, 1);
  add_link(a, 0, 2, 4);
  add_link(a, 0, 3, 6);
  add_link(a, 0, 4, 4);
  add_link(a, 1, 2, 2);
  add_link(a, 2, 3, 1);
  add_link(a, 3, 4, 1);
  add_link(a, 1, 3,1);
  int *prev = malloc(sizeof(int) * size);
  djikstra(a, 0, prev);
  queue *s = shortest_path(prev, 0, 3);
  printarray(s->values, s->length, "shortest_path");

}