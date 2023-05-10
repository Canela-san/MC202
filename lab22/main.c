#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "struct.c"

int main(void)
{
    int temp = 1;
    char entrada[200];
    char comando[15];
    char nome[200];
    char *det;
    while (temp)
    {
        list *L = (list *)malloc(sizeof(list));
        L->head = NULL;
        L->indicator = NULL;
        scanf("%d", &temp);
        if (temp == 0)
            break;
        for (int k = 0; k < temp; k++)
        {
            fgets(entrada, sizeof(entrada), stdin);
            det = strtok(entrada, " ");
            strcpy(comando, det);
            strcpy(nome, "");
            Lplay(L);
            while (det)
            {
                det = strtok(NULL, " ");
                if (det != NULL)
                {
                    strcat(nome, det);
                    strcat(nome, " ");
                }
                else
                    strcat(nome, "\0");
            
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
        //Lfree(L);
    }

    return 0;
}
