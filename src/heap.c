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
heap* create_max_heap(int capacity, int* nums)
{
    heap* h = (heap*)malloc(sizeof(heap));
 
    if (h == NULL) {
        printf("Erro");
        return NULL;
    }

    h->size = 0;
    h->capacity = capacity;
 
    h->arr = (int*)malloc(capacity * sizeof(int));
 
    if (h->arr == NULL) {
        printf("Erro");
        return NULL;
    }
    int i;
    
    for (i = 0; i < capacity; i++)
    {
        h->arr[i] = nums[i];
    }
 
    h->size = i;
    i = (h->size - 2) / 2;
    while (i >= 0) {
        max_heapify(h, i);
        i--;
    }
    return h;
}

/**
 * @brief Insere um valor no heap
 * 
 * @param h 
 * @param data 
 */
void insert_max_heap(heap* h, int data)
{
 
    if (h->size < h->capacity) {
        h->arr[h->size] = data;
        insert_organize(h, h->size);
        h->size++;
    }
}

/**
 * @brief Deleta um nó do heap
 * 
 * @param h 
 */
void delete_node(heap* h)
{
    int delete;
 
    if (h->size == 0) {
        printf("Heap vazio\n");
        return;
    }

    delete = h->arr[0];
 

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
 
    if (h->arr[parent] < h->arr[index]) {

        int temp = h->arr[parent];
        h->arr[parent] = h->arr[index];
        h->arr[index] = temp;
 
        insert_organize(h, parent);
    }
}

void max_heapify(heap* h, int index)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int max = index;

    if (left >= h->size || left < 0)
        left = -1;
    if (right >= h->size || right < 0)
        right = -1;
 

    if (left != -1 && h->arr[left] > h->arr[max])
        max = left;
    if (right != -1 && h->arr[right] > h->arr[max])
        max = right;
 
    if (max != index) {
        int temp = h->arr[max];
        h->arr[max] = h->arr[index];
        h->arr[index] = temp;
 
        max_heapify(h, max);
    }
}