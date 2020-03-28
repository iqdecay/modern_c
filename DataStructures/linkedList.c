#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
    int head;
    struct node *tail;
} list;

void append(list *l, int i) {
    if (l->tail == NULL) {
        list *t;
        t = malloc(sizeof(list));
        t->tail = NULL;
        t->head = i;
        l->tail = t;
        return;
    } else {
        append(l->tail, i);
    }
}
list newList(int i){
}

list buildList(int array[], size_t size)
{
    if (size == 0) {
        list l;
       return l;
    }
}

int lastElement(list *l) {
    if (l->tail == NULL) return l->head;
    return lastElement(l->tail);
}

void printList(list *l) {
    if (l->tail == NULL){
        printf("%d.\n", l->head);
        return;
    }
    printf("%d,", l->head);
    printList(l->tail);
    return;
}


//int main() {
//    list *test;
//    test = malloc(sizeof(list));
//    test->tail = NULL;
//    test->head = 10;
//    printList(test);
//    append(test, 1);
//    printList(test);
//    append(test, 2);
//    printList(test);
////    int array[4] = {1, 2, 3, 4};
////    list test_append = buildlist(array, 4);
////    printf("%d\n", (test_append.tail)->tail->tail->head);
////    printf("%d\n", isInlist(&test, 0));
////    printlist(&test_append);
//////    printf("%d\n", isInlist(test_append, 4));
////
////
////    list test1;
////    test1.tail = NULL;
////    test1.head = 1;
////    list test2;
////    test2.tail = &test1;
////    test2.head = 2;
////    list test3;
////    test3.tail = &test2;
////    test3.head = 3;
////    printlist(&test3);
//}
