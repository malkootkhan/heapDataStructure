#ifndef __HEAPDS__H
#define __HEAPDS__H

#include <stdio.h>
#include <stdlib.h>
/**
 * struct heap
 * @max_size:  maximum size of heap
 * @curr_size: currently available data
 * @data:     data storage
 */

struct heap {
    int *data;
    int max_size;
    int curr_size;
};
/*lower layer functions*/
void heapifyUp(struct heap *h, int index);
void heapifyDown(struct heap *h, int index);
int parentIndex(int index);
int leftChild(int index);
int rightChild(int index);


struct heap *createHeap(int cap);
void insert(struct heap *h, int data);
int delete(struct heap *h);
void display(struct heap *h);

#endif
