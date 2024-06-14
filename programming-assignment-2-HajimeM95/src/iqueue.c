#include <stdlib.h>
#include <stdio.h>
#include "iqueue.h"

#if 0
  int capacity;		// maximum capacity of data
  int size;		// the current number of items in data
  int front;		// index of the front of the queue
  int back;           // index of the back of the queue
  long *data;		// array of longs - stores all stack data 
#endif
void iqueue_init(iqueue_t *queue)
{
    queue->capacity=8;
    queue->size=0;
    queue->front=-1;
    queue->back=-1;
    queue->data=(long *)(malloc(queue->capacity * sizeof(long)));
}

void iqueue_enqueue(iqueue_t *queue, long item)
{
    iqueue_ensure_capacity(queue); /* if queue full capacity*2 */
    if (queue->back < 0) {
        queue->back=0;
        queue->front=0;
    } else {
        queue->back = (queue->back + 1) % queue->capacity;
    }
    queue->data[queue->back] = item;
    queue->size++;
}

long iqueue_dequeue(iqueue_t *queue)
{
    long r = queue->data[queue->front];
    if (queue->front == queue->back) {
        queue->front = -1;
        queue->back = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    queue->size--;
    return (r);
}

long iqueue_peek(iqueue_t *queue)
{
    return queue->data[queue->front];
}

int iqueue_ensure_capacity(iqueue_t *queue)
{
    int c=queue->capacity;
    if ((queue->size + 1) <= queue->capacity) return 1;
    queue->capacity *= 2;
    queue->data = (long *) realloc(queue->data, queue->capacity * sizeof(long));
    if (queue->front == 0) return 0;
    for (int i=queue->back; i<0; i--) {
        queue->data[i+c]=queue->data[i];
    }
    queue->back += c;
    return 0;
}

void iqueue_destroy(iqueue_t *queue)
{
    queue->capacity=0;
    queue->size=0;
    queue->front=-1;
    queue->back=-1;
    free(queue->data);
    queue->data=(long *) NULL;
}
