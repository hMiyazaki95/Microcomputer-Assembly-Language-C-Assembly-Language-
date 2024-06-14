//
// Interface for QueueList data structure
//

typedef struct queue_list_t {
  list_node_t *front;  // front of the queue
  list_node_t *back;   // back of the queue
} queue_list_t; 


queue_list_t *queue_list_init();

void queue_list_enqueue(queue_list_t *queue, void *item);

void *queue_list_dequeue(queue_list_t *queue);

void *queue_list_peek(queue_list_t *queue);

int queue_list_size(queue_list_t *queue);

void queue_list_destroy(queue_list_t *queue);
