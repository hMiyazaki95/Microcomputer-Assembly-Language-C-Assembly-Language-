#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memlib.h"
#include "alloc.h"
#define ALIGNMENT 8
#define MIN_BLOCK_SIZE 24

/**
 *HEAP STATE
 */
char *heap_begin;
char *heap_end;

/**
 *PRIVATE HELPER FUNCTIONS
 */

/**
 *Given a size and whether the block is allocated, returns the encoded header.
 */
size_t make_header(size_t size, size_t alloc)
{
    return size | alloc;
}

/**
 *Given a pointer to a header/footer, returns true if the block is allocated.
 */
size_t is_allocated(void *header_ptr)
{
    return (*((size_t *) header_ptr)) & 0x1;
}

/**
 *Given a pointer to a header/footer, returns the TOTAL size of the block.
 */
size_t get_size(void *header_ptr)
{
    return (*((size_t *) header_ptr)) & ~0x7;
}

/**
 *Given a pointer to a header/footer, returns the data storage size in the block. 
 */
size_t get_capacity(void *header_ptr)
{
    long size = get_size(header_ptr);

    // Subtract space for header and footer.
    return size - sizeof(size_t) * 2;
}

/**
 *Given a pointer to a header, return the data storage pointer within a block.
 */
void *get_data_addr(void *header_ptr)
{
    // data resides at base addr + header size
    return header_ptr + sizeof(size_t);
}

/**
 *Given a number, returns the closest number divisibly by 8.
 *Blocks (header + footer + data) must be 8 byte aligned.
 */
size_t closest_block_size(size_t numbytes)
{
    while (numbytes % ALIGNMENT != 0)
    {
        numbytes += 1;
    }

    return numbytes;
}

/**
 *Prints the last three digits of an address.
 *Useful for keeping tests simple.
 */
void print_short_address(void *ptr)
{
    unsigned long short_ptr = (unsigned long) ptr;
    short_ptr &= 0xFFF;
    printf("0x%03lx", short_ptr);
}

/**
 *Given a header, block size, and allocated, writes both a header and footer
 *into the block. Uses the block size to determine where the header is located.
 */
void block_write_hf(char *header_ptr, size_t block_size, size_t alloc)
{
    // Write header
    size_t *block_header = (size_t *) header_ptr;
    *block_header = make_header(block_size, alloc);

    // Write footer
    size_t *block_footer = (size_t *)(header_ptr + block_size - sizeof(size_t));
    *block_footer = make_header(block_size, alloc);
}

/**
 *Splits the provided block if possible given the number of bytes needed.
 *Returns the block size post split. 
 *If the block is not split, returns the original size. 
 *Assume that request_size includes space for the header and footer already!
 */
size_t block_split(char *header_ptr, size_t request_size)
{
    size_t size = get_size(header_ptr);
    size_t diff = size - request_size;

    // TODO: implement split
    if (diff == 0) return request_size;
  
    block_write_hf(header_ptr + request_size, diff, 0);
    
    // If the block is not able to be split.
    return diff;
}

/**
 *Coalesces blocks before and after the given block.
 *Returns a pointer to the new block.
 *Will free any block given to this function.
 */
void block_coalesce(void *ptr)
{
    // TODO: implement coalesce
    size_t c, b, f, r;
    void *p = ptr;
    c = get_size(ptr);
    b = 0;
    f = 0;
    r = 0;

    if (is_allocated(ptr)) return;
    
    // check next block for free block;
    p += c;
    if ((heap_end > (char *)p) && !is_allocated(p)) {
        f=get_size(p);
        // printf("debug: after buffer free\n");
        block_write_hf(ptr, f+c, 0);
        return;
    }
    
    // check previous block for free block;
    p = ptr-sizeof(size_t);
    if ((heap_begin <= (char *)p) && !is_allocated(p)) {
        // printf("debug: before buffer free\n");
        b=get_size(p);
        r=b;
        p=p-b;
    }

    p += sizeof(size_t);
    if(r==0)
    {
    return;
    }
    // printf("debug: p=");
    // print_short_address(p);
    // printf(" s=%d f=%d r=%d c=%d\n",f+r+c,f,r,c);
    block_write_hf(p, r+c, 0);
    // cis20_traverse_heap();
}


#ifdef NDEF
/**
 *Coalesces blocks before and after the given block.
 *Returns a pointer to the new block.
 *Will free any block given to this function.
 */
void block_coalesce(void *ptr)
{
    // TODO: implement coalesce
    size_t c, b, f, r;
    void *p = ptr;
    c = get_size(ptr);
    b = 0;
    f = 0;
    r = 0;
    long is_alloc = is_allocated(p);
    // loop thorough next block for free block;
    if (!is_allocated(p))
    {
        b = get_size(p);
        f += b;
        p += b;
        if(heap_end < (char *)p)
        {
        break;
        }
    }
    p = (ptr-sizeof(size_t));
    while(heap_begin < (char *)p && !is_allocated(p))
    {
        b = get_size(p);
        r += b;
        p = p-b;
    }
    p += sizeof(size_t);
    if((f==c)&&(r==0))
    {
    return;
    }
    block_write_hf(p, f+r, 0);
}
#endif

/**
 *Headers and footers are implemented as integers.
 */
void cis20_init()
{
    // char *block_fit = (char *) NULL;

    // Intialize memory library.
    mem_init();
    
    // TODO: intialize first heap block
    // block_fit = (char *) mem_sbrk(24);
    // block_write_hf(block_fit, 24, 0);
    block_write_hf(mem_sbrk(24), 24, 0);

    heap_begin = (char *) mem_heap_lo();
    heap_end = (char *) mem_heap_hi();

//    block_write_hf(heap_begin, 24, 0);
    // Allocate first free list item.
    // Request 16 bytes (8 header + 8 data + 8 footer).
    // Must be 8 byte aligned.

    // Remember: low => high

    printf("Initializing heap...\n");
    printf("BEGIN: ");
    print_short_address(heap_begin);
    printf(", END: ");
    print_short_address(heap_end);
    printf(", SIZE: %lu\n\n", mem_heapsize());
}

void cis20_deinit()
{
    // Deinit memory library.
    mem_deinit();
}

void *cis20_alloc(size_t numbytes)
{
    // TODO: convert pseudocode
    heap_begin = (char *) mem_heap_lo();
    heap_end = (char *) mem_heap_hi();
    char *current_header = (char *) heap_begin;
    char *block_fit = (char *) NULL;
    size_t block_size = 0;
    size_t request_size = closest_block_size(numbytes + sizeof(size_t) * 2);
    
    // printf("DEBUG: numbytes %d, request_size %d\n", numbytes, request_size);

    while (current_header < heap_end)
    {
        long size = get_size(current_header);
        long is_alloc = is_allocated(current_header);
        
        if (size == 0) 
        {
            break;
        }
        if (!is_alloc && (size >= request_size))
        {
            printf("Block found at ");
            print_short_address(current_header);
            printf("\n");
            block_fit = current_header;
            block_size = request_size;
            break;
        }
        current_header += size;
    }
    if (block_fit == NULL)
    {
            printf("Unable to find block to accommodate %lu (%lu) bytes.\n", request_size, numbytes);
            printf("Requesting new block of size: %lu\n", request_size);
            char *new_block = (char *) mem_sbrk(request_size);
            printf("New block starts at ");
            print_short_address(new_block);
            printf("\n");

        if ((long) new_block != -1)
        {
            block_fit = new_block;
            block_size = request_size;
            heap_end = (char *) mem_heap_hi();
        }
        else
        {
            printf("Unable tp expand heap\n");
            return NULL;
        }
        printf("block size: %ld\n", block_size);
    }
    else
    {
            (void) block_split(block_fit, request_size);
            printf("block size: %ld\n", block_size);
    }
    block_write_hf(block_fit, block_size, 1);
    return get_data_addr(block_fit);
}

void cis20_free(void *data_ptr)
{
    // TODO: convert pseudocode
    
    //Subtract one word to get to header.
    
    char* header_ptr = ((char *) data_ptr) - sizeof(size_t);
    size_t size = get_size(header_ptr);
    
    // Overwrite old header/footer. Set alloc to 0.
    block_write_hf(header_ptr, size, 0);
    
    // After freeing, attempt to coalesce.
    block_coalesce(header_ptr);
}

void cis20_traverse_heap()
{
    char *current_header = heap_begin;

    printf("- Heap State - size: %lu bytes --------------------\n", mem_heapsize());
    printf("---------------------------------------------------\n");

    while (current_header < heap_end)
    {
        int size = get_size(current_header);
        int alloc = is_allocated(current_header);
        long data_size = size - sizeof(size_t) * 2;
        char data[data_size + 1];
        memcpy(data, current_header + sizeof(size_t), data_size);
        data[data_size] = '\0';

        print_short_address(current_header);
        printf("\t size: %d  data size: %ld  alloc: %d\n", size, data_size, alloc);

        printf("\t hdr: 0x%x ftr: 0x%x\n", *current_header, *(current_header + data_size + sizeof(size_t)));
        printf("\t data: %s ", data);

        // If the block is unallocated, notify.
        if (alloc == 0)
        {
            printf("(junk)");
        }

        printf("\n");
        printf("---------------------------------------------------\n");

        if (size == 0)
        {
            break;
        }

        current_header += size;
    }

    printf("\n");
}