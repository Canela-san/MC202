#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "struct.c"

    void
    zerarArray(char array[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        array[i] = '\0';
    }
}

int main(void)
{
    int temp = 1;
    char entrada[100];
    char comando[15];
    char nome[50];
    char *det;
    while (temp)
    {
        list *L = (list *)malloc(sizeof(list));
        L->head = NULL;
        L->indicator = NULL;
        scanf("%d", &temp);
        if (temp == 0)
            break;
        getchar();
        for (int k = 0; k < temp; k++)
        {
            zerarArray(entrada, 100);
            zerarArray(comando, 15);
            zerarArray(nome, 50);

            fgets(entrada, sizeof(entrada), stdin);
            det = strtok(entrada, " ");
            printf("---%s----", det);
            strcpy(comando, det);
            if (strlen(comando) > 0 && comando[strlen(comando) - 1] == '\n')
            {
                comando[strlen(comando) - 1] = '\0';
            }
            printf("COMANDO: -%s-\n", comando);
            while (det)
            {
                det = strtok(NULL, " ");
                if (det != NULL)
                {
                    strcat(nome, det);
                    if (strlen(nome) > 0 && nome[strlen(nome) - 1] == '\n')
                    {
                        nome[strlen(nome) - 1] = '\0';
                    }
                    else
                    {
                        strcat(nome, " ");
                    }
                }
            }
            if (strcmp(comando, "insere") == 0)
            {
                Linsert(L, nome);
            }
            if (strcmp(comando, "remove") == 0)
            {
                Lremove(L, nome);
            }
            if (strcmp(comando, "final") == 0)
            {
                Lfinal(L);
            }
            if (strcmp(comando, "volta") == 0)
            {
                Lgo_back(L);
            }
            if (strcmp(comando, "toca") == 0)
            {
                Lplay(L);
            }
            if (strcmp(comando, "inverte") == 0)
            {
                Linvert(L);
            }
        }
        Lfree(L);
    }
    return 0;
}
