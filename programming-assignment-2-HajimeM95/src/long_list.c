#include "long_list.h"
#include <stdlib.h>
#include <stdio.h>

long_list_node_t *long_list_init()
{
    return ((long_list_node_t *)malloc(sizeof(long_list_node_t)));
}

void long_list_print(long_list_node_t *head)
{
    long_list_node_t *p=head;
    p=NULL; /* Comment this for debug */
    while (p != (long_list_node_t *) NULL) {
        printf ("DEBUG: p=%p p->data=%li p->next=%p\n", p, p->data, p->next);
        p=p->next;
    }
}

void long_list_add(long_list_node_t *head, long item)
{
    long_list_node_t *p, *o;
    p=head;
    o=head;
    /* printf ("DEBUG: head=%p data=%i item=%i\n", head, head->data, item); */
    while (p != (long_list_node_t *) NULL) {
        o=p;
        p=p->next;
    }
    p = long_list_init();
    p->data = item;
    p->next = NULL;
    o->next=p;
    /* printf ("DEBUG: p=%p p->data=%i item=%i p->next=%p\n", p, p->data, item, p->next); */
    /* printf ("DEBUG: head=%p data=%i item=%i next=%p\n", o, o->data, item, o->next); */
    //long_list_print(head);
    /* printf ("DEBUG: ADD DONE\n"); */
    return;
}

long long_list_get(long_list_node_t *head, int index)
{
    long_list_node_t *p;
    p = head;
    for(int i = 0; i < index; i++){
        p = p->next;
        
    }
    return p->data;
}

int long_list_set(long_list_node_t *head, int index, long item)
{
    long_list_node_t *p;
    int i = 0;
    p = head;
    
    if (index <= 0) return 0;
    
    while (p !=  (long_list_node_t *) NULL) {
        if (i == index) {
            p->data = item;
            return 1;
        }
        i++;
        p = p->next;
    }
    return 0;
}

void long_list_remove(long_list_node_t *head, int index)
{
    long_list_node_t *p, *op;
    int i = 0;
    
    //long_list_print (head);
    op = head;
    p = head;
    if (index == 0) {
        if (head->next == NULL) {
            return;
        }
        p=head->next;
        head->data=p->data;
        head->next=p->next;
        //long_list_print (head);
        return;
    }
    while (p != NULL) {
        /* printf ("p=%p i=%i\n", p, i); */
        if (i == index) {
            op->next = p->next;
            //long_list_print (head);
            return;
        }
        op = p;
        p = p->next;
        i++;
    }
    //long_list_print (head);
}


int long_list_contains(long_list_node_t *head, long item)
{
    long_list_node_t *p;
    
    //long_list_print (head);

    p = head; 
    while (p !=  (long_list_node_t *) NULL) {
        if (p->data == item)
            return 1;
        p = p->next;
    }
    return 0;
}

int long_list_size(long_list_node_t *head)
{
    long_list_node_t *p;
    int s = 0;
    p = head;
    while (p != NULL)
    {
        s++;
        p = p->next;
    }
    return s;
}

void long_list_destroy(long_list_node_t *head)
{
    long_list_node_t *p, *o;
    p=head;
    o=head;
    while(p != (long_list_node_t *) NULL)
    {
        o=p;
        free(p);
        p=o->next;
    }
    return;
}
