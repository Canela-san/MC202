#include <stdio.h>
#include "arvore.h"
#include "arvore.c"




#include <stdio.h>
#include <string.h>

#define NAME_SIZE 100
#define COMMAND_SIZE 100


int main() {
    char comando[COMMAND_SIZE];

    while (1) {
        printf("Digite um comando: ");
        scanf("%s", comando);

        if (strcmp(comando, "criar") == 0) {
            // Lógica para o comando "criar"
        }
        else if (strcmp(comando, "inserir") == 0) {
            long int k;
            char nome[NAME_SIZE];
            float valor;

            scanf("%d, %[^,], %f", &k, nome, &valor);

            // Lógica para o comando "inserir"
            printf("insere k=%d, nome=%s, valor=\n");
        }
        else if (strcmp(comando, "imprimir") == 0) {
            // Lógica para o comando "imprimir"
            printf("imprime\n");
        }
        else if (strcmp(comando, "buscar") == 0) {
            long int valor;

            scanf("%d", &valor);

            printf("busca %d\n", valor);
            // Lógica para o comando "buscar"
        }
        else if (strcmp(comando, "buscar-intervalo") == 0) {
            long int inicio, fim;

            scanf("%d %d", &inicio, &fim);
            printf("busca %d - %d\n", inicio, fim);
            // Lógica para o comando "buscar-intervalo"
        }
        else if (strcmp(comando, "remover") == 0) {
            long int valor;

            scanf("%d", &valor);
            printf("remove %d\n", valor);
            // Lógica para o comando "remover"
        }
        else if (strcmp(comando, "predecessor") == 0) {
            long int valor;

            scanf("%d", &valor);
            printf("predecessor %d\n", valor);
            // Lógica para o comando "predecessor"
        }
        else if (strcmp(comando, "sucessor") == 0) {
            long int valor;

            scanf("%d", &valor);
            printf("sucessor %d\n", valor);
            // Lógica para o comando "sucessor"
        }
        else if (strcmp(comando, "minimo") == 0) {
            // Lógica para o comando "minimo"
            printf("minimo\n");
        }
        else if (strcmp(comando, "maximo") == 0) {
            // Lógica para o comando "maximo"
            printf("maximo\n");
        }
        else if (strcmp(comando, "terminar") == 0) {
            printf("termina\n");
            break;
        }
        else {
            printf("Comando inválido!\n");
        }
    }

    return 0;
}
