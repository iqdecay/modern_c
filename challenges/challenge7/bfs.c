//
// Created by lulwat on 21/03/2020.
//
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "adjacency.h"

queue *bfs_graph(adjaMatrix *a, int root)
{
  size_t size = a->size;
  queue *q = init_queue(size);
  add_queue(q, root);
  int current;
  int discovered[size];
  memset(discovered, 0, sizeof(int) * size);
  discovered[root] = 1;
  queue *res = init_queue(size);
  while (length_queue(q) > 0) {
    current = pop_queue(q);
    add_queue(res, current);
    for (size_t i = 0; i < size; i++) {
      if (get_link(a, current, i) && (!discovered[i])) {
        add_queue(q, i);
        discovered[i] = 1;
      }
    }
  }
  return res;
}

//int main(void)
//{
//  // First, build an undirected graph
//  int size = 10;
//  queue *q = init_queue(size);
//  adjaMatrix *a = init_adja(size);
//  add_link(a, 0, 1, 1);
//  add_link(a, 0, 2, 1);
//  add_link(a, 1, 3, 1);
//  add_link(a, 2, 4, 1);
//  add_link(a, 2, 5, 1);
//  add_link(a, 3, 6, 1);
//  add_link(a, 4, 7, 1);
//  add_link(a, 4, 8, 1);
//  add_link(a, 5, 9, 1);
//  queue *r = bfs_graph(a, 2);
//  for (size_t i = 0; i < size; i++) {
//    printf("%i \n", pop_queue(r));
//  }
//}


