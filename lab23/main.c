// Feito por Gabriel Canela, RA243453.
// Arquivo main.c

#include <stdio.h>
#include <stdlib.h>
#include "sublista.h"
// Função main está feita de forma reduzida.
// todas as operações estão em formato de funções, com definições localizadas no arquivo sublista.c
// as declarações das funções estão no arquivo sublista.h

int main(void)
{
    list *L = criar_lista(); // função para alocar memória para a lista L, e define valores iniciais.
    ler_lista(L);             // função para ler a primeira entrada, que define a lista inicial.
    executar_comandos(L);     // função para criar um loop que executa os comando de entrada 's' e '+'.
    libera_lista(L);          // função para liberar a memória alocada pela lista.
    return 0;
}