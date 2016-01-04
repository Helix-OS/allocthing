#ifndef _a_malloc_thing
#define _a_malloc_thing

// tunable parameters, maximum allocatable size is BLOCK_SIZE * NUM_BINS
#define BLOCK_SIZE 32
#define NUM_BINS   32

typedef struct heap_block {
	unsigned size;
	struct heap_block *next;
} heap_block_t;

typedef struct uheap {
	heap_block_t *bins[NUM_BINS + 1];
} uheap_t;

void *uheap_alloc( uheap_t *heap, unsigned size );
void uheap_free( uheap_t *heap, void *ptr );

#endif
