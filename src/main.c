#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "heap.h"
#include "funcionalidades.h"

// Declara a raiz do heap como variável global
heap* vheap = NULL;

void exibirMenu() {
    printf("Seja bem-vindo(a) ao sistema de controle de trafego áereo!\n");
    printf("1 - Carregar dados de um arquivo\n");
    printf("2 - Inserir aeronave\n");
    printf("3 - Consultar maior prioridade\n");
    printf("4 - Remover maior prioridade\n");
    printf("5 - Atualizar prioridade\n");
    printf("6 - Exibir heap\n");
}

int main() 
{
    setlocale(LC_ALL, "Portuguese");
    int opcoes;
    char nome_arquivo[256];

    do 
    {
        exibirMenu();
        scanf("%d", &opcoes);
        getchar();

        switch(opcoes) 
        {
            // Carregar dados de um arquivo
            case 1:
                printf("Digite o nome do arquivo: ");
                fgets(nome_arquivo, 256, stdin);
                nome_arquivo[strcspn(nome_arquivo, "\n")] = 0;
                vheap = lerArquivo(nome_arquivo, vheap);
                break;
            // Inserir aeronave
            case 2:
                Voo voo;
                printf("Digite o código da aeronave: ");
                fgets(voo.identificador, sizeof(voo.identificador), stdin);
                voo.identificador[strcspn(voo.identificador, "\n")] = 0;
                printf("Digite o combustível da aeronave: ");
                scanf("%d", &voo.combustivel);
                printf("Digite o horário de chegada da aeronave: ");
                scanf("%d", &voo.horario_de_chegada);
                printf("Digite o tipo de operação da aeronave (1 - Pouso, 0 - Decolagem): ");
                scanf("%d", &voo.tipo_de_operacao);
                printf("Digite se a aeronave está em estado de emergência (1 - Sim, 0 - Não): ");
                scanf("%d", &voo.emergencia);
                voo.prioridade = calcularPrioridade(&voo);
                getchar();
                vheap = inserirAeronave(vheap, voo);
                break;
            // Consultar maior prioridade
            case 3:
                consultarMaiorPrioridade(vheap);
                break;
            // Remover maior prioridade
            case 4:
                removerMaiorPrioridade(vheap);
                break;
            // Atualizar prioridade
            case 5:
                int codigo, prioridade;
                printf("Digite o código da aeronave: ");
                scanf("%d", &codigo);
                printf("Digite a nova prioridade da aeronave: ");
                scanf("%d", &prioridade);
                vheap = atualizarPrioridade(vheap, codigo, prioridade);
                break;
            // Exibir heap
            case 6:
                exibirHeap(vheap);
                break; 
            // Encerrar programa
            case 0:
                printf("Encerrar programa.\n");
                exit(0);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcoes != 0);
    return 0;

}