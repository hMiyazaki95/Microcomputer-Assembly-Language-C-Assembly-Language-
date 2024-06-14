//
// Interface for IQueue data structure.
//

typedef struct {
  int capacity;		// maximum capacity of data
  int size;		// the current number of items in data
  int front;		// index of the front of the queue
  int back;           // index of the back of the queue
  long *data;		// array of longs - stores all stack data 
} iqueue_t;


void iqueue_init(iqueue_t *queue);

void iqueue_enqueue(iqueue_t *queue, long item);

long iqueue_dequeue(iqueue_t *queue);

long iqueue_peek(iqueue_t *queue);

int iqueue_ensure_capacity(iqueue_t *queue);

void iqueue_destroy(iqueue_t *queue);
