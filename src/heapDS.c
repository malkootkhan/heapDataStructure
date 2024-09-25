#include <stdio.h>
#include <stdlib.h>
#include "heapDS.h"


struct heap *createHeap(int cap)
{
    struct heap *h = (struct heap *)malloc(sizeof(struct heap));
    h->curr_size = 0;
    h->data = (int *)malloc(sizeof(int) * cap);
    h->max_size = cap;
    return h;
}
int parentIndex(int index)
{
    return ((index - 1)/2);
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void heapify(struct heap *h, int index)
{
    while(index > 0 && h->data[index] > h->data[parentIndex(index)]){
        swap(&h->data[index], &h->data[parentIndex(index)]);
        index = parentIndex(index);
    }
}
void insert(struct heap *h, int data)
{
    int index = h->curr_size;
    if(index == 0){
        h->data[index] = data;
        goto out;
    }
    if(h->curr_size >= h->max_size){
        printf("heap is full!\n");
        goto out;
    };
    h->data[index] = data;
    
    heapify(h, index);

out:
    h->curr_size++;
}

void display(struct heap *h)
{
    for(int i = 0; i < h->curr_size; i++)
        printf("%d ", h->data[i]);
    printf("\n");
}


