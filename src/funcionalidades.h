#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

#include "heap.h"
#include "voo.h"

int calcularPrioridade(Voo* v);
heap* lerArquivo(char* nome_arquivo, heap* h);
heap* inserirAeronave(heap* h, Voo voo);
void consultarMaiorPrioridade(heap* h);
void removerMaiorPrioridade(heap* h);
heap* atualizarPrioridade(heap* h, int codigo, int prioridade);
void exibirHeap(heap* h);
void limparArvore(heap* h);

#endif