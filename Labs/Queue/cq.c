#include <stdlib.h>
#include <stdio.h>
#include "cq.h"

void create_queue(cq **cq, int size){
    (* cq) = malloc(sizeof(cq));
    (*cq) -> q = (int *)malloc(size * sizeof(int));
    (*cq) -> start = -1;
    (*cq) -> end = -1;
    (*cq) -> len = size;
}

void destroy_queue(cq *cq){
    free(cq -> q);
    free(cq);
}

void resize(cq *cq){
    int newsz = (cq -> len) * 2;
    int * newq = malloc(sizeof(int) * newsz);

    int i = cq -> start;
    int idx = 0;

    while (1){
        newq[idx ++] = cq -> q[i];
        if (i == cq -> end){break;}
        i = (i + 1) % cq -> len;
    }
    
    free(cq -> q);
    cq -> q = newq;
    cq -> start = 0;
    cq -> end = idx -1;
    cq -> len = newsz;
}

void enqueue(cq *cq, int data){
    if (((cq -> end) + 1) % cq -> len == cq -> start){
        resize(cq);
    }
    if (cq -> start == -1){
        cq -> start = 0;
    }
    cq -> end = ((cq -> end) + 1) % (cq -> len);
    cq -> q[cq -> end] = data;
}

void print_queue(cq *cq) {
    int i = cq->start;
    printf("Queue: ");
    while (1) {
        printf("%d ", cq->q[i]);
        if (i == cq->end) {
            break;
        }
        i = (i + 1) % cq->len;
    }
    printf("\n");
}

//get element at idx zero, remove it and then return it.
int dequeue(cq *cq){
    int ret = cq -> q[cq -> start];
    cq -> q[cq -> start] = 0;

    if (cq -> start == cq -> end){
        cq -> start = cq -> end = -1;
    } else{
        cq -> start = ((cq -> start) + 1)% cq -> len;
    }
    return ret;
}

int main() {
    cq *cq;
    create_queue(&cq, 4);  // Start with a small size to test resizing
    
    enqueue(cq, 10);
    enqueue(cq, 12);
    enqueue(cq, 7);
    enqueue(cq, 15);
    print_queue(cq);
    
    enqueue(cq, 20);  // Should trigger resize
    print_queue(cq);
    
    printf("Dequeue: %d\n", dequeue(cq));  // Should return 10
    print_queue(cq);
    
    destroy_queue(cq);  // Free memory
    return 0;
}