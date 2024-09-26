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
void heapifyUp(struct heap *h, int index)
{
    while(index > 0 && h->data[index] > h->data[parentIndex(index)]){
        swap(&h->data[index], &h->data[parentIndex(index)]);
        index = parentIndex(index);
    }
}
int leftChild(int index)
{
    return (2*index + 1);
}
int rightChild(int index)
{
    return (2*index + 2); 
}
void heapifyDown(struct heap *h, int index)
{
    int pIndex = index;
    int lIndex = leftChild(pIndex);
    int rIndex = rightChild(pIndex);
    if(lIndex < h->curr_size && h->data[pIndex] < h->data[lIndex])
        pIndex = lIndex;
    if(rIndex < h->curr_size && h->data[pIndex] < h->data[rIndex])
        pIndex = rIndex;

    if(pIndex != index){
        swap(&h->data[index], &h->data[pIndex]);
        heapifyDown(h, pIndex);
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
    
    heapifyUp(h, index);

out:
    h->curr_size++;
}
int delete(struct heap *h)
{
    if(h->curr_size <= 0) {
        printf("The heap is empty\n");
        return -1;
    }
    int val = h->data[0];
    h->data[0] = h->data[h->curr_size - 1];
    h->curr_size--;
    heapifyDown(h, 0);
    return val;
}
void display(struct heap *h)
{
    for(int i = 0; i < h->curr_size; i++)
        printf("%d ", h->data[i]);
    printf("\n");
}


