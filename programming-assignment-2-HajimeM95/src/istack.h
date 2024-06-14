//
// Interface for IStack data structure
//

typedef struct {
  int capacity;		// maximum capacity of data
  int size;		    // the current number of items in data
  int index;		// index to the top of data
  long *data;		// array of longs - stores all stack data 
} istack_t; 


void istack_init(istack_t *stack);

void istack_push(istack_t *stack, long item);

long istack_pop(istack_t *stack);

long istack_peek(istack_t *stack);

int istack_ensure_capacity(istack_t *stack);

void istack_destroy(istack_t *stack);
