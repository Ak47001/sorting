#ifndef _INCLUDED_HEAP_
#define _INCLUDED_HEAP_

#include <stdint.h>
#define HEAP_MAX_SIZE 32

typedef struct _heap_ Heap;
struct  _heap_
{
	uint32_t	size;
	int32_t		data[HEAP_MAX_SIZE]	;
};

Heap 		heap_new(int32_t data[], uint32_t len);
Heap*		heap_sort(Heap *heap);
Heap*		heap_insert(Heap *heap, int32_t key);
Heap*		heap_test(Heap *heap);
int32_t		heap_get_max(Heap *heap);
int32_t		heap_extract_max(Heap *heap);
uint32_t	heap_size(Heap *heap);

#endif