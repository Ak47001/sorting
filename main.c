#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include<conio.h>
#include"sort.h"
void testcase()
{
    int32_t list1[7]={20,45,78,34,87,10,5};
    int32_t list2[5]={90,55,71,21,10};
    int32_t list3[7]={80,65,81,31,47,140,185};
    int32_t list4[7]={8,65,1,31,7,140,155};
    int32_t list5[7]={89,65,17,31,79,140,155};
    bubble_sort(list1,7);
    selection_sort(list2,5);
    insertion_sort(list3,7);
    quick_sort(list4,0,6);
    display(list4,7);
    merge_sort(list5,0,6);
    display(list5,7);
}
int main()
{
    testcase();
    return 0;
}
