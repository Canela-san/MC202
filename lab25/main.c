// Feito por Gabriel Canela, RA243453.
// Arquivo main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "arvore.c"
//Os tamanhos de variaveis como NAME_SIZE estão no arquivo arvore.h

int main()
{
    char comando[COMMAND_SIZE];
    Node *T = NULL;
    while (1)
    {
        printf("Digite um comando: ");
        scanf("%s", comando);

        if (strcmp(comando, "criar") == 0)
        {
            printf("criar\n");
            //adicionar free para a arvore
            T = NULL;
        }
        else if (strcmp(comando, "inserir") == 0)
        {
            long int k;
            char nome[NAME_SIZE];
            float valor;

            scanf("%ld, %[^,], %f", &k, nome, &valor);
            inserir(&T, k, nome, valor);
            // Lógica para o comando "inserir"
            printf("insere k=%ld, nome=%s, valor=%f\n", k, nome, valor);
        }
        else if (strcmp(comando, "imprimir") == 0)
        {
            // Lógica para o comando "imprimir"
            
            printf("Comando imprimir:\n\n");
            imprimir(T);
            printf("\n\n");
        }
        else if (strcmp(comando, "buscar") == 0)
        {
            long int valor;

            scanf("%ld", &valor);

            printf("busca %ld\n", valor);
            // Lógica para o comando "buscar"
        }
        else if (strcmp(comando, "buscar-intervalo") == 0)
        {
            long int inicio, fim;

            scanf("%ld %ld", &inicio, &fim);
            printf("busca %ld - %ld\n", inicio, fim);
            // Lógica para o comando "buscar-intervalo"
        }
        else if (strcmp(comando, "remover") == 0)
        {
            long int valor;

            scanf("%ld", &valor);
            printf("remove %ld\n", valor);
            // Lógica para o comando "remover"
        }
        else if (strcmp(comando, "predecessor") == 0)
        {
            long int valor;

            scanf("%ld", &valor);
            printf("predecessor %ld\n", valor);
            // Lógica para o comando "predecessor"
        }
        else if (strcmp(comando, "sucessor") == 0)
        {
            long int valor;

            scanf("%ld", &valor);
            printf("sucessor %ld\n", valor);
            // Lógica para o comando "sucessor"
        }
        else if (strcmp(comando, "minimo") == 0)
        {
            // Lógica para o comando "minimo"
            printf("minimo\n");
        }
        else if (strcmp(comando, "maximo") == 0)
        {
            // Lógica para o comando "maximo"
            printf("maximo\n");
        }
        else if (strcmp(comando, "terminar") == 0)
        {
            printf("termina\n");
            break;
        }
        else
        {
            printf("Comando inválido!\n");
        }
    }

    return 0;
}
