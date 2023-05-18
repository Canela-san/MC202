#include <stdio.h>
#include <stdlib.h>
#include "sublista.h"

int main(void)
{
    list *L = (list *)malloc(sizeof(list));
    if (L == NULL)
    {
        printf("Erro na alocação de memória\n");
        return 1;
    }

    L->head = NULL;
    L->size = 0;

    ler_lista(L);
    executar_comandos(L);
    libera_lista(L);

    return 0;
}