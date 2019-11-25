#include <stdio.h>
#include <stdbool.h>

typedef struct List {
    int head;
    struct List *tail;
} List;

int append(List *l, int i){
    if (l->tail == NULL) {
        List tail;
        tail.head = i;
        tail.tail = NULL;
        l->tail = &tail;
    } else {
        append(l->tail, i);
    }
}

List buildList(int array[], size_t size){
    List l;
    l.tail = NULL;
    l.head = array[0];
    if (size == 1) {
        return l;
    }
    for (int i = 1; i < size; i++){
        append(&l, array[i]);
    }
    return l;
}

int main() {
    List test;
    test.tail = NULL;
    test.head = 0;
    append(&test, 500);
    append(&test, 100000);
    int array[4] = {1,2,3,4};
    List test_append = buildList(array, 4);
    printf("%d\n",(test_append.tail)->tail->tail->head);


//    List test1;
//    test1.tail = &test;
//    test1.head = 1;
//    List test2;
//    test2.tail = &test1;
//    test2.head = 2;
//    struct List test3;
//    test3.tail = &test2;
//    test3.head = 3;
//    printf( "%d\n", (test2.tail)->tail->head);
}
