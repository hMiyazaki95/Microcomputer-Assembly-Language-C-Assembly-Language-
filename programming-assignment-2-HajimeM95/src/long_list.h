// 
// Interface for LongList data structure.
// This is a singly linked list that stores only longs.
//

typedef struct long_list_node {
  struct long_list_node* next;  // pointer to next item
  long data;  // single long item
} long_list_node_t;

long_list_node_t *long_list_init();

void long_list_add(long_list_node_t *head, long item);

long long_list_get(long_list_node_t *head, int index);

int long_list_set(long_list_node_t *head, int index, long item);

void long_list_remove(long_list_node_t *head, int index);

int long_list_contains(long_list_node_t *head, long item);

int long_list_size(long_list_node_t *head);

void long_list_destroy(long_list_node_t *head);
