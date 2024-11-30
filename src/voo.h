#ifndef VOO_H
#define VOO_H

#include <string.h>

typedef struct
{
    char identificador[20];
    int combustivel;
    int horario_de_chegada;
    int tipo_de_operacao;
    int emergencia;
    int prioridade;
} Voo;

#endif