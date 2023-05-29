// Feito por Gabriel Canela, RA243453.
// Arquivo main.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.h"

// as funções tem definições localizadas no arquivo sublista.c
// as declarações das funções estão no arquivo sublista.h

int main(void)
{
    char frase[400], pre[200], in[200];
    while (1)
    {
        strcpy(frase, "");
        fgets(frase, sizeof(frase), stdin);
        if (strlen(frase) <= 1)
            return 0;
        sscanf(frase, "%s %s", pre, in);
        Node *root = reconstruir_arvore(pre, in);
        PrintPosOrder(root);
        printf(" ");
        printTreeByLevel(root);
        printf("\n");
        freeTree(root);
    }
    return 0;
}