#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


/**
 * @brief Cria um heap
 * 
 * @param capacity 
 * @param nums 
 * @return heap* 
 */
heap* create_max_heap(int capacity, Voo* voos)
{
    heap* h = (heap*)malloc(sizeof(heap));
    h->size = 0;
    h->capacity = capacity;
    h->arr = (Voo*)malloc(sizeof(Voo) * capacity);
    return h;
}

/**
 * @brief Insere um valor no heap
 * 
 * @param h 
 * @param data 
 */
void insert_max_heap(heap* h, Voo value)
{
    if (h->size == h->capacity) {
        printf("Heap cheio\n");
        return;
    }
 
    h->arr[h->size] = value;
    h->size++;
 
    insert_organize(h, h->size - 1);
}

/**
 * @brief Deleta um nó do heap
 * 
 * @param h 
 */
void delete_node(heap* h)
{
    if (h->size == 0) {
        printf("Heap vazio\n");
        return;
    }
 
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
 
    max_heapify(h, 0);
}

/**
 * @brief Reorganiza o heap depois de uma inserção
 * 
 */
void insert_organize(heap* h, int index)
{
    int parent = (index - 1) / 2;
 
    if (index == 0)
        return;
    if (h->arr[index].prioridade > h->arr[parent].prioridade) {
        Voo temp = h->arr[index];
        h->arr[index] = h->arr[parent];
        h->arr[parent] = temp;
 
        insert_organize(h, parent);
    }
}

/**
 * @brief Reorganiza o heap depois de uma remoção
 * 
 * @param h 
 * @param index 
 */
void max_heapify(heap* h, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int max = index;
 
    if (left < h->size && h->arr[left].prioridade > h->arr[max].prioridade)
        max = left;
    if (right < h->size && h->arr[right].prioridade > h->arr[max].prioridade)
        max = right;
 
    if (max != index) {
        Voo temp = h->arr[index];
        h->arr[index] = h->arr[max];
        h->arr[max] = temp;
 
        max_heapify(h, max);
    }
}