#include <stdlib.h>
#include "ArrayList.h"

typedef struct queue{
    AL *list;
}queue;

typedef struct CircQ{
    AL *q;
    int start_ind;
    int end_ind;
    int len;
}CircQ;

void create_queue(queue **p_q);
void destroy_queue(queue *q);

void enqueue(queue *q, int data);
int dequeue(queue *q);
