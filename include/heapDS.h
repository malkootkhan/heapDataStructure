#ifndef __HEAPDS__H
#define __HEAPDS__H

#include <stdio.h>
#include <stdlib.h>
/**
 * struct heap
 * @max_size:  maximum size of heap
 * @curr_size: currently available data
 * @array:     data storage
 */
struct heap
{
    int max_size;
    int curr_size;
    int *array;
};

struct heap *createHeap(int maxSize);

#endif
