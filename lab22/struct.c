#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void Linsert(list *L, char nome[150])
{
    node *no = (node *)malloc(sizeof(node));
    no->name = (char *)malloc(strlen(nome) + 1);
    no->next = NULL;
    no->prev = NULL;
    strcpy(no->name, nome);

    if (L->head == NULL)
    {
        L->head = no;
        L->indicator = no;
    }
    else if (L->indicator->next == NULL)
    {
        no->prev = L->indicator;
        no->next = NULL;
        L->indicator->next = no;
    }
    else
    {
        no->prev = L->indicator;
        no->next = L->indicator->next;
        L->indicator->next->prev = no;
        L->indicator->next = no;
    }
}

// Lremove remove um nó da lista que contem o mesmo name
void Lremove(list *L, char name[150])
{
    node *lixo = NULL;
    node *aux = L->head;

    // Verifica se a lista está vazia
    if (aux == NULL)
    {
        return;
    }

    // Percorre a lista até encontrar o nó com o mesmo nome ou chegar ao fim
    while (aux != NULL && strcmp(aux->name, name) != 0)
    {
        aux = aux->next;
    }

    // Verifica se encontrou o nó com o nome especificado
    if (aux != NULL && strcmp(aux->name, name) == 0)
    {
        lixo = aux;
        if (L->head == lixo)
        {
            // Verifica se a lista tem mais de um nó
            if (L->head->next != NULL)
            {
                L->head = lixo->next;
                L->head->prev = NULL;
            }
            else
            {
                L->head = NULL;
                L->indicator = NULL;
            }
            if (L->indicator == lixo)
                L->indicator = lixo->next;
        }
        else
        {
            lixo->prev->next = lixo->next;
            if (lixo->next != NULL)
                lixo->next->prev = lixo->prev;
        }
        free(lixo->name); // Libera a memória alocada para o nome do nó
        free(lixo);       // Libera a memória alocada para o nó
    }
}

// Lplay exibe o nome da musica atual e avança o indicador para o proximo item da lista
int Lplay(list *L)
{
    if (L->indicator != NULL)
    {
        printf("%s\n", L->indicator->name);
        if (L->indicator->next != NULL)
        {
            L->indicator = L->indicator->next;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("\n");
    }
    return 1;
}

// Lgo_back volta o indicador em um item da lista
void Lgo_back(list *L)
{
    if (L->indicator != NULL && L->indicator->prev != NULL)
    {
        L->indicator = L->indicator->prev;
    }
}

void Lfinal(list *L)
{
    while (Lplay(L))
        ;
}

// Linvert inverte a ordem da lista, não muda a pusição do indicador
void Linvert(list *L)
{
    if (L->head == NULL || L->head->next == NULL)
        return;

    node *atual = L->head;
    node *aux = NULL;

    while (atual)
    {
        aux = atual->prev;
        atual->prev = atual->next;
        atual->next = aux;
        atual = atual->prev;
    }

    // Atualiza o indicador para o novo primeiro nó (ENUNCIADO DIZ PARA NÃO FAZER ISSO)
    // L->indicator = L->head;
    // Atualiza a cabeça da lista
    L->head = aux->prev;
}

void Lfree(list *L)
{
    if (L == NULL)
        return;

    node *current = L->head;
    while (current != NULL)
    {
        node *temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }

    free(L);
}
