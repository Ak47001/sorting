#include<stdint.h>
#include<stdlib.h>
#include"heap.h"
#include<string.h>
#include<assert.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
static void _swap_(int32_t *list1,int32_t *list2)
{
    int32_t temp;
    temp=*list1;
    *list1=*list2;
    *list2=temp;
}
int32_t heap_size(Heap *heap)
{
    return heap->size;
}
static void _heapify_(int32_t data[],int32_t len,int32_t parent)
{
    //printf("%d\n",len);
    //printf("%d",parent);
    //assert(len>0 && len<HEAP_MAX_SIZE); //&& parent>0);
    int32_t child=2*parent;
    while(child<=len)
    {
        if(child+1<=len){
            if(data[child+1]>data[child])
            {
                ++child;
            }
        }
        if(data[parent]>=data[child])
        {
            break;
        }
        _swap_(&data[parent],&data[child]);
        parent=child;
        child=2*parent;
        //printf("%d\n",len);
    }
}
static void _test_heap_(int32_t data[],int32_t len)
{
    for(int32_t idx=len;idx>1;--idx)
    {
        assert(data[idx]<=data[idx/2]);
    }
}
Heap heap_new(int32_t data[],int32_t len)
{
    assert(len>0 && len<HEAP_MAX_SIZE);
    Heap heap;
    int32_t parent;
    for(parent=len/2;parent>0;--parent)
    {
        _heapify_(data,len,parent);
        //printf("%d\n",parent);

    }
    heap.size=len;
    memcpy(heap.data,data,(len+1)*sizeof(int32_t));
    _test_heap_(heap.data,heap.size);
    return heap;
}
/*
Heap* heap_sort(Heap *heap)
{
    int32_t i;

    // One by one extract an element from heap
    for (i=heap->size-1; i>=0; i--)
    {
        // Move current root to end
        _swap_(&heap->data[0],&heap->data[i]);

        // call max heapify on the reduced heap
        _heapify_(heap->data, i, 0);
    }
}
*/


Heap* heap_sort(Heap *heap)
{
    assert(heap->size>0 && heap->size<HEAP_MAX_SIZE);
    for(int32_t idx=heap->size;idx>0;--idx)
    {
        _swap_(&heap->data[1],&heap->data[idx]);
        _heapify_(heap->data,idx-1,1);

    }
    //_swap_(&heap->data[1],&heap->data[2]);
    printf("%d\n",heap->data[0]);
    printf("\n");
    return heap;
}
void display_heap(Heap *heap,int32_t len)
{
    int32_t i;
    for(i=0;i<len;i++)
    {
        printf("%d\t",heap->data[i]);
    }
}
