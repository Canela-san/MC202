#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "struct.h"
// #include "struct.c"


int main(){
        // list *L = (list *)malloc(sizeof(list));
    // L->head = NULL;
    // L->indicator = NULL;

    // Linsert(L, "Gabriel Canela");
    // Linsert(L, "Zezin ped");
    // Linsert(L, "waku waku");

    int temp = 1;
    char entrada[200];
    char comando[15];
    char nome[200];
    char *det;
    while (temp)
    {
        scanf("%d", &temp);
        if (temp == 0)
            break;
        for (int k = 0; k < temp; k++)
        {
            fgets(entrada, sizeof(entrada), stdin);
            det = strtok(entrada, " ");
            strcpy(comando, det);
            strcpy(nome, "");
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
                    printf(",%s,", det);
                }
                else
                {
                    // strcat(nome, '\0');
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
        // Lfree(L);
    }
    return 0;
}