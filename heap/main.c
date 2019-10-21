#include<stdint.h>
#include<stdlib.h>
#include"heap.h"
//#include<string.h>
void test_heap()
{
    int32_t list1[]={20,45,78,34,87,10,5,58,12,11};
    Heap h;
    h=heap_new(list1,10);
    Heap *he=&h;
    he=heap_sort(he);
    assert(he->size==10);
    display_heap(he,10);
    assert(he->size==10);

}
int main()
{
    test_heap();
    return 0;
}
