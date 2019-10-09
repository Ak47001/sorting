#include<stdint.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "sort.h"
void display(int32_t list[],uint32_t size)
{
    int32_t i;
    for(i=0;i<size;i++)
    {
        printf("%d\t",list[i]);
    }
    printf("\n");
}
static void _swap_(int32_t *list1,int32_t *list2)
{
    //printf("hello");
    int32_t temp;
    temp=*list1;
    //printf("%d",temp);
    *list1=*list2;
    *list2=temp;
}
void bubble_sort(int32_t list[],uint32_t size)
{
    uint32_t pass,index;
    for(pass=0;pass<size-1;++pass)
    {
        for(index=size-1;index>pass;--index)
            if(list[index]<list[index-1])
            {

                _swap_(&list[index],&list[index-1]);
            }

    }
    display(list,size);
}
void selection_sort(int32_t list[],uint32_t size)
{
    uint32_t pass,index,min_pos;
    for(pass=0;pass<size-1;++pass)
    {
        min_pos=pass;
        for(index=pass+1;index<size;++index)
        {
            if(list[index]<list[min_pos])
            {
                min_pos=index;
            }
        }
        _swap_(&list[pass],&list[min_pos]);
    }
    display(list,size);
}
void insertion_sort(int32_t list[],uint32_t size)
{
    int32_t pass,index,key;
    for(pass=1;pass<size;++pass)
    {
        key=list[pass];
        index=pass-1;
        while(index>=0 && list[index]>key)
        {
            list[index+1]=list[index];
            --index;
        }
        list[index+1]=key;
    }
    display(list,size);
}
static uint32_t _partion_(int32_t list[],uint32_t start,uint32_t end)
{
    uint32_t up,down;
    int32_t pivot=list[start];
    up=start;
    down=end;
    do
    {
        while(pivot>=list[up] && up<=down)
        {
            ++up;
        }
        while(pivot<list[down] && up<=down)
        {
            --down;
        }
        if(up<=down)
        {
            _swap_(&list[up],&list[down]);
        }
    }while(up<=down);
    _swap_(&list[start],&list[down]);
    return down;
}
void quick_sort(int32_t list[],int32_t start,int32_t end)
{
    int32_t mid;
    if(start<end)
    {
        mid=_partion_(list,start,end);
        quick_sort(list,start,mid-1);
        quick_sort(list,mid+1,end);
    }

}
static void _merge_(int32_t list[],int32_t low,int32_t mid,int32_t high)
{
    uint32_t f_index,s_index,t_index,idx;
    int32_t temp[high+1];
    f_index=t_index=low;
    s_index=mid+1;
    while(f_index<=mid && s_index<=high)
    {
        if(list[f_index]<=list[s_index])
        {
            temp[t_index++]=list[f_index++];
        }
        else{
            temp[t_index++]=list[s_index++];
        }
    }
    if(f_index>mid)
    {
        for(idx=s_index;idx<=high;++idx)
        {
            temp[t_index++]=list[idx];
        }
    }
    else
    {
        for(idx=f_index;idx<=mid;++idx)
        {
            temp[t_index++]=list[idx];
        }
    }
    for(idx=low;idx<=high;++idx)
    {
        list[idx]=temp[idx];
    }
}

void merge_sort(int32_t list[],int32_t low,int32_t high)
{
    int32_t mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(list,low,mid);
        merge_sort(list,mid+1,high);
        _merge_(list,low,mid,high);
    }
}

