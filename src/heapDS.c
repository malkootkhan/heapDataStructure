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

void swap(int *first, int *second)
{
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

/**
 * insert function
 * @heap structure
 * @data: data to be stored
 */
void insert(struct heap *h, int data)
{
    // Check if the heap is full (assuming capacity is defined)
    if (h->curr_size >= h->max_size) {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }

    // Insert the new data at the end of the heap array
    int index = h->curr_size;
    h->array[index] = data;  // Insert at the last position
    h->curr_size++;

    // Heapify up (fix the heap property)
    while (index != 0 && h->array[getParentIndex(index)] < h->array[index]) {
        // Swap with parent if the parent is smaller
        int parentIndex = getParentIndex(index);
        swap(&h->array[parentIndex], &h->array[index]);

        // Move up to the parent index
        index = parentIndex;
    }
}


