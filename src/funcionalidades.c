#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionalidades.h"
#include "voo.h"

/**
 * @brief Calcula a prioridade de um voo
 * 
 * @param v 
 * @return int 
 */
int calcularPrioridade(Voo* v)
{
    int prioridade = (1000 - v->combustivel) + (1440 - v->horario_de_chegada) + 500 * (v->tipo_de_operacao) + 5000 * (v->emergencia);
    return prioridade;
}

/**
 * @brief Lê um arquivo e insere os voos no heap
 * 
 * @param nome_arquivo 
 * @param h 
 * @return heap* 
 */
heap* lerArquivo(char* nome_arquivo, heap* h)
{
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return NULL;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo))
    {
        //FL123,200,600,1,0

        Voo* v = (Voo*)malloc(sizeof(Voo));
        sscanf(linha, "%[^,],%d,%d,%d,%d", v->identificador, &v->combustivel, &v->horario_de_chegada, &v->tipo_de_operacao, &v->emergencia);
        int prioridade = calcularPrioridade(v);
        v->prioridade = prioridade;
        h = inserirAeronave(h, *v);
    }
    fclose(arquivo);
    printf("Arquivo lido com sucesso\n");
    return h;
}

/**
 * @brief Insere uma aeronave no heap
 * 
 * @param h 
 * @param voo 
 * @return heap* 
 */
heap* inserirAeronave(heap* h, Voo voo)
{
    if (h == NULL)
    {
        h = create_max_heap(100, NULL);
    }
    insert_max_heap(h, voo);
    return h;
}

/**
 * @brief Consulta a maior prioridade do heap
 * 
 * @param h 
 */
void consultarMaiorPrioridade(heap* h)
{
    if (h == NULL)
    {
        printf("Heap vazio\n");
        return;
    }
    printf("Maior prioridade: %d\n", h->arr[0].prioridade);
}

/**
 * @brief Remove a maior prioridade do heap
 * 
 * @param h 
 */
void removerMaiorPrioridade(heap* h)
{
    if (h == NULL)
    {
        printf("Heap vazio\n");
        return;
    }
    delete_node(h);
}

/**
 * @brief Atualiza a prioridade de um voo
 * 
 * @param h 
 * @param codigo 
 * @param prioridade 
 * @return heap* 
 */
heap* atualizarPrioridade(heap* h, int codigo, int prioridade)
{
    if (h == NULL)
    {
        printf("Heap vazio\n");
        return NULL;
    }
    for (int i = 0; i < h->size; i++)
    {
        if (h->arr[i].prioridade == codigo)
        {
            h->arr[i].prioridade = prioridade;
            max_heapify(h, i);
            break;
        }
    }
    return h;
}

/**
 * @brief Exibe o heap
 * 
 * @param h 
 */
void exibirHeap(heap* h)
{
    if (h == NULL)
    {
        printf("Heap vazio\n");
        return;

    }
    Voo tempHeap[h->size];
    for (int i = 0; i < h->size; i++)
    {
        tempHeap[i] = h->arr[i];
    }

    for (int i = 0; i < h->size - 1; i++)
    {
        for (int j = i + 1; j < h->size; j++)
        {
            if (tempHeap[i].prioridade < tempHeap[j].prioridade)
            {
                Voo temp = tempHeap[i];
                tempHeap[i] = tempHeap[j];
                tempHeap[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < h->size; i++)
    {
        printf("Código: %s\n", tempHeap[i].identificador);
        printf("Combustível: %d\n", tempHeap[i].combustivel);
        printf("Horário de chegada: %d\n", tempHeap[i].horario_de_chegada);
        printf("Tipo de operação: %d\n", tempHeap[i].tipo_de_operacao);
        printf("Estado de emergência: %d\n", tempHeap[i].emergencia);
        printf("Prioridade: %d\n", tempHeap[i].prioridade);
        printf("\n");
    }
}

/**
 * @brief Limpa a árvore
 * 
 * @param h 
 */
void limparArvore(heap* h)
{
    free(h->arr);
    free(h);
}