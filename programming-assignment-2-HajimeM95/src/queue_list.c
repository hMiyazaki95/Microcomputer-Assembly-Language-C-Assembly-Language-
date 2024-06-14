#include "linked_list.h"
#include "queue_list.h"
#include <stdlib.h>

void queue_list_init(iqueue_t *queue)
{
    int capacity = 8;
    int size = 0;
    int front = -1;
    int back = -1;
    long data=(long int*) malloc(8* sizeof(long));
    
}

#ifdef NDEF
void queue_list_enqueue(queue_list_t *queue, void *item)
{
    (void) istack_ensure_capacity (item);
    queue->size++;
    queue->back++; 
    queue->data[stack->front]=item;
}

void *queue_list_dequeue(queue_list_t *queue)
{
    queue_list_t *p, *op;
    int i = 0;
    
    queue_list_print (queue);
    op = queue;
    p = queue;
    if (front == 0) {
        if (queue->item == NULL) {
            front++;
            return;
        }
        p=queue->back;
        queue->data=p->data;
        queue->back=p->back;
        queue_list_t (queue);
        return;
    }
    while (p != NULL) {
        /* printf ("p=%p i=%i\n", p, i); */
        if (back == front) {
            op->back = p->back;
            queue_list_t (queue);
            return;
        }
        op = p;
        p = p->back;
        front++;
    }
    queue_list_print (head);
    return stack->data[stack->index];
}

void *queue_list_peek(queue_list_t *queue)
{
    return queue->data[queue->front];
}
int iqueue_ensure_capacity(iqueue_t *queue)
{
    if (queue->size < queue->capacity) return 1;
    queue->capacity *= 2;
    queue->data = (long int*)realloc(queue->data, (queue->capacity) * sizeof(long));
    return 0;
}

void queue_list_destroy(queue_list_t *queue)
{
    queue->front=-1;
    queue->capacity=0;
    queue->size=0;
    queue->data=(long int *) NULL;
}
#endif NDEF

