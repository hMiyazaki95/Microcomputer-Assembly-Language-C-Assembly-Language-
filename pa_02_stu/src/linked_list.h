//
// Interface for LinkedList data structure
//

typedef struct list_node {
  struct list_node* next;  // pointer to next item
  struct list_node* prev;  // pointer to previous item
  void *data;              // pointer to a single list item
} list_node_t;


list_node_t *linked_list_init();

void linked_list_add(list_node_t *head, void *item);

void *linked_list_get(list_node_t *head, int index);

int linked_list_set(list_node_t *head, int index, void *item);

void linked_list_remove(list_node_t *head, int index);

int linked_list_contains(list_node_t *head, void *item);

int linked_list_size(list_node_t *head);

void linked_list_destroy(list_node_t *head);
