#include <stdlib.h>

typedef struct adjaMatrix adjaMatrix;
struct adjaMatrix {
    size_t size;
    int **matrix;
};

adjaMatrix *init_adja(size_t size);

int add_link(adjaMatrix * m, int node1, int node2, int value);
int get_link(adjaMatrix * m, int node1, int node2);

