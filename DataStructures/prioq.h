#include <stdlib.h>

typedef struct prioq prioq;
struct prioq{
    size_t capacity;
    size_t length;
    int *values;
    int * priorities;

};
prioq * init_prioq(size_t max_size);
int pop_prioq(prioq *pq);
prioq * add_prioq(prioq *pq, int elt, int prio);
size_t length_prioq(prioq *pq);
size_t capacity_prioq(prioq *pq);
