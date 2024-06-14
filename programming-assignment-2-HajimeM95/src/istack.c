#include "istack.h"
#include <stdlib.h>
#include <stdio.h>

void istack_init(istack_t *stack)
{
  stack->index = -1;
  stack->size = 0;
  stack->capacity = 8;
  stack->data=(long int*) malloc(8* sizeof(long));
}

void istack_push(istack_t *stack, long item)
{
    (void) istack_ensure_capacity (stack);
    stack->size++;
    stack->index++; 
    stack->data[stack->index]=item;
}

long istack_pop(istack_t *stack)
{
    long r=stack->data[stack->index];
    stack->index--;
    stack->size--;
    return r;
}

long istack_peek(istack_t *stack)
{
    return stack->data[stack->index];
}

int istack_ensure_capacity(istack_t *stack)
{
    if (stack->size < stack->capacity) return 1;
    stack->capacity *= 2;
    stack->data = (long int*)realloc(stack->data, (stack->capacity) * sizeof(long));
    return 0;
}

void istack_destroy(istack_t *stack)
{
    stack->index=-1;
    stack->capacity=0;
    stack->size=0;
    stack->data=(long int *) NULL;
}


