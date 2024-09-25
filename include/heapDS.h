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
struct heap *createHeap(int cap);
void insert(struct heap *h, int data);
void display(struct heap *h);

#endif
