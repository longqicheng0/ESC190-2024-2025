#include <stdlib.h>

typedef struct cq{
    int *q;
    int start;
    int end;
    int len;
}cq;

void create_queue(cq **p_cq, int size);
void destroy_queue(cq *cq);

void enqueue(cq *cq, int data);
int dequeue(cq *cq);
