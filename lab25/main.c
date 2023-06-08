// Feito por Gabriel Canela, RA243453.
// Arquivo main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
// Os tamanhos de variaveis como NAME_SIZE e COMMAND_SIZE estão no arquivo arvore.h

int main()
{
    char comando[COMMAND_SIZE];
    Node *T = NULL;
    Node *aux;
    int temp = 0;
    while (1)
    {
        scanf("%s", comando);

        if (strcmp(comando, "criar") == 0)
        {
            freeTree(T);
            T = NULL;
        }
        else if (strcmp(comando, "inserir") == 0)
        {
            long int k;
            char nome[NAME_SIZE];
            float valor;
            scanf("%ld, %[^,], %f", &k, nome, &valor);
            inserir(&T, k, nome, valor);
        }
        else if (strcmp(comando, "imprimir") == 0)
        {
            if (T)
            {
                printf("clientes: ");
                imprimir(T);
                printf("\n");
            }
            else
                printf("arvore vazia\n");
        }
        else if (strcmp(comando, "buscar") == 0)
        {
            long int valor;
            scanf("%ld", &valor);
            Node *no = buscar(T, valor);
            if (no)
            {
                printf("cliente %ld: ", valor);
                printf("%s, %.2f pontos\n", no->name, no->pontos);
            }
            else
                printf("nao ha cliente %ld\n", valor);
        }
        else if (strcmp(comando, "buscar-intervalo") == 0)
        {
            long int inicio, fim;
            scanf("%ld %ld", &inicio, &fim);
            printf("clientes no intervalo [%ld,%ld]: ", inicio, fim);
            imprimir_intervalo(T, inicio, fim, &temp);
            if (!temp)
                printf("nenhum");
            temp = 0;
            printf("\n");
        }
        else if (strcmp(comando, "remover") == 0)
        {
            long int valor;
            scanf("%ld", &valor);
            T = removeNode(T, valor);
        }
        else if (strcmp(comando, "predecessor") == 0)
        {
            long int valor;
            scanf("%ld", &valor);
            printf("predecessor %ld\n", valor);
        }
        else if (strcmp(comando, "sucessor") == 0)
        {
            long int valor;
            scanf("%ld", &valor);
            printf("sucessor %ld\n", valor);
        }
        else if (strcmp(comando, "minimo") == 0)
        {
            aux = minimo(T);
            printf("minimo: %ld\n", aux->k);
        }
        else if (strcmp(comando, "maximo") == 0)
        {
            aux = maximo(T);
            printf("maximo: %ld\n", aux->k);
        }
        else if (strcmp(comando, "terminar") == 0)
        {
            freeTree(T);
            return 0;
        }
        else
            printf("Comando inválido!\n");
    }

    return 0;
}
