
#include<stdint.h>
#include<assert.h>
#include<stddef.h>
#include<stdlib.h>
#ifndef _INCLUDED_HEAP_
#define _INCLUDED_HEAP_
#define HEAP_MAX_SIZE 32
typedef struct _heap_ Heap;
struct _heap_{
    int32_t size;
    int32_t data[HEAP_MAX_SIZE];
};
Heap heap_new(int32_t data[],int32_t len);
Heap* heap_sort(Heap *heap);
int32_t heap_size(Heap *heap);
void display_heap(Heap *heap,int32_t len);
#endif // _INCLUDED_HEAP_
