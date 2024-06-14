#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>


list_node_t *linked_list_init()
{
    list_node_t *p;
    p = (list_node_t *)malloc(sizeof(list_node_t));
    p->prev=NULL;
    p->next=NULL;
    p->data=(void *) NULL;

    return p;
}

void linked_list_add(list_node_t *head, void *item)
{
    
    list_node_t *p = head;
    while (p->next != (list_node_t *) NULL)
    {
        p = p->next;
    }
    
    p->next = (list_node_t *) (malloc (sizeof (list_node_t)));
    p->next->next = (list_node_t *) NULL;
    p->next->prev = p;
    p->next->data = item;
    return;
}

void *linked_list_get(list_node_t *head, int index)
{
    list_node_t *p = head;
    int i=-1;
    while (p != (list_node_t *) NULL)
    {
        if (i == index) {
            return p->data;
        }
        i++;
        p = p->next;
    }
    return (NULL);
}

int linked_list_set(list_node_t *head, int index, void *item)
{
    list_node_t *p = head;
    int i=-1;
    while (p != (list_node_t *) NULL)
    {
        if (i==index) {
            p->data = item;
            return 1;
        }
        i++;
        p = p->next;
    }
    return 0;
}

void linked_list_remove(list_node_t *head, int index)
{
    list_node_t *p = head;
    int i=-1;
    if (p->next == (list_node_t *) NULL) {
        return;
    }
    while (p != (list_node_t *) NULL)
    {
        if (p->data)
            printf ("debug: i=%d, index=%d, p=%p, data=%d\n", i, index, p, *(int *)p->data);
        if (i == index) {
            list_node_t *c = p, *p1=p->prev, *p2=p->next;
            if (c->data != NULL)
                printf ("debug: i=%d, index=%d, p=%p, data=%d\n", i, index, p, *(int *)c->data);
           
            p->prev->next=p2;
            if (p2 != NULL) p->next->prev=p1;
            
            return;
        }
        i++;
        p = p->next;
    }
}

int linked_list_contains(list_node_t *head, void *item)
{
    list_node_t *p = head;
    while (p != (list_node_t *) NULL)
    {
        if (p->data == item) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int linked_list_size(list_node_t *head)
{
    list_node_t *p = head;
    int i=0;
    while (p != (list_node_t *) NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}

void linked_list_destroy(list_node_t *head)
{
    list_node_t *p = head;
    while (p != (list_node_t *) NULL)
    {
        list_node_t *c = p;
        p = p->next;
        free(c);
    }
}
