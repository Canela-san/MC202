// Feito por Gabriel Canela, RA243453

#include <stdio.h>
#include <stdlib.h>
#include "sublista.h"

int main(void)
{
    // ainda não está usando a list A, mas irá
    char comando;
    int start, end, indice, temp;
    list *L = (list *)malloc(sizeof(list));
    L->head = NULL;
    L->size = 0;

    // pega a entrada e printa em outro formato
    scanf("A = {%d", &start);
    insere_fim(L, start);
    while (1)
    {
        temp = scanf(", %d", &start);
        if (temp == 0)
            break;
        else
            insere_fim(L, start);
    }
    getchar();
    getchar();

    list *A = (list *)malloc(sizeof(list));

    // pega o primeiro caractere como comando, caso f finaliza o programa.
    while (1)
    {
        scanf("%c", &comando);
        if (comando == 'f')
            return 0;

        if (comando == 's')
        {
            scanf(" A[%d..%d]", &start, &end);
            L = create_sublist(L, start, end);
            all_print(L);
        }
        else if (comando == '+')
        {
            scanf(" A[%d..%d] %d", &start, &end, &indice);
            insere_sublista(L, create_sublist(L, start, end), indice);
            all_print(L);
        }
    }
    return 0;
}
