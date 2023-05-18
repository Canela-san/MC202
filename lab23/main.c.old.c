// Feito por Gabriel Canela, RA243453
// Nesse código não há vetores (arrays), incluindo variáveis com strings (cadeias de caracteres).

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

    // pega a entrada e insere na lista encadeada L
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

    //libera os caracteres a mais no stdinput '} '.
    getchar();
    getchar();  

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
            print_L(L);
        }
        else if (comando == '+')
        {
            scanf(" A[%d..%d] %d", &start, &end, &indice);
            insere_sublista(L, create_sublist(L, start, end), indice);
            print_L(L);
        }
    }
    return 0;
}
