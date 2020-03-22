//
// Created by lulwat on 21/03/2020.
//

#ifndef MODERN_C_QUEUE_H
#define MODERN_C_QUEUE_H

#include <stdlib.h>

typedef struct queue queue;
struct queue {
    int capacity;
    int *values;
    int length;
};

queue * init_queue(int max_size);

int pop_queue(queue *q);

queue * add_queue(queue *q, int elt);

size_t length_queue(queue *q);

size_t capacity_queue(queue *q);

#endif //MODERN_C_QUEUE_H
