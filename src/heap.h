#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} heap;

heap* create_max_heap(int capacity, int* nums);
void insert_max_heap(heap *heap, int value);
void delete_node(heap *heap);
void insert_organize(heap* h, int index);
void max_heapify(heap* h, int index);

#endif
