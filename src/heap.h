#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>
#include "voo.h"
typedef struct
{
    Voo *arr;
    int size;
    int capacity;
} heap;


heap* create_max_heap(int capacity, Voo* voos);
void insert_max_heap(heap *heap, Voo value);
void delete_node(heap *heap);
void insert_organize(heap* h, int index);
void max_heapify(heap* h, int index);

#endif
