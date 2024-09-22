#include "heapDS.h"

/**
 * createHeap function
 * @maxSize: maximum heap size
 * @return: return initialized heap pointer
 */
int getParentIndex()
{
    return 0;
}
int getLeftChild()
{
    return 0;
}
int getRightIndex()
{
    return 0;
}
struct heap *createHeap(int maxSize)
{
    struct heap *h = (struct heap*)malloc(sizeof(struct heap));
    h->max_size = maxSize;
    h->curr_size = 0;
    h->array = (int *)malloc(sizeof(int)*maxSize);
    return h;
}

void append(int index, int data)
{
    
}

/**
 * insert function
 * @heap structure
 * @data: data to be stored
 */

void insert(struct heap *h, int data)
{
    if(!h->curr_size){
        h->array[getParentIndex(h->curr_size)] = data;
        h->curr_size++;
        return;
    }
    int index = h->curr_size;
    append(index, data);
    while(data > h->array[index-1]){
            h->array[index] = h->array[index-1];
            index--;
    }
    h->array[index - 1];
    h->curr_size++;

}

void display(struct heap *h)
{
    for(int i = 0; i < h->curr_size; i++)
        printf("%d ", h->array[i]);
    printf("\n");
}

