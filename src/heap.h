#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} heap;

heap* create_max_heap(int capacity);
void insert_max_heap(heap *heap, int value);
int extract_max(heap *heap);
void free_max_heap(heap *heap);
bool is_empty(heap *heap);
void print_heap(heap *heap);

#endif
