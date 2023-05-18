#include <stdio.h>
#include <stdlib.h>
#include "sublista.h"

//insere o valor no fim da lista encadeada
void insere_fim(list *L, int valor)
{
    int indice = 0;
    node *novo = (node *)malloc(sizeof(node));
    novo->valor = valor;
    novo->next = NULL;

    if (L->head == NULL)
    {
        novo->indice = indice;
        novo->prev = NULL;
        L->head = novo;
    }
    else
    {
        node *aux = L->head;
        while (aux->next)
        {
            aux = aux->next;
            indice++;
        }
        aux->next = novo;
        novo->prev = aux;
        novo->indice = ++indice;
    }
    L->size++;
}

//printa todos os valores da lista encadeada
void print_L(list *L)
{
    printf("A: {");
    if (L->head == NULL)
        return;
    node *aux = L->head;
    while (aux)
    {
        printf(" %d", aux->valor);
        aux = aux->next;
        if (aux)
            printf(",");
    }
    printf(" }\n");
}

//Insere uma sublista encadeada em outra lista encadeada em uma posição indice.
void insere_sublista(list *L, list *sublist, int indice)
{
    if (L->head == NULL || sublist->head == NULL)
        return;
    else
    {
        node *aux1 = L->head;
        node *aux2 = sublist->head;

        if (indice >= L->size)
        {
            while (aux1->next)
            {
                aux1 = aux1->next;
            }
            aux1->next = aux2;
            aux2->prev = aux1;
        }
        else
        {
            if (indice) //confere se a inserção é na posição 0, caso não seja:
            {
                while (aux1->indice != indice)
                    aux1 = aux1->next;
                while (aux2->next != NULL)
                    aux2 = aux2->next;
                aux1->prev->next = sublist->head;
                sublist->head->prev = aux1->prev;
                aux2->next = aux1;
                aux1->prev = aux2;
            } else {    //tratamento para caso seja na posição 0:
                L->head = aux2;
                while (aux2->next != NULL)
                    aux2 = aux2->next;
                aux1->prev = aux2;
                aux2->next = aux1;
            }
        }
        aux1 = L->head;
        int novo_indice = 0;
        while (aux1)
        {
            aux1->indice = novo_indice;
            novo_indice++;
            aux1 = aux1->next;
        }
        L->size = novo_indice;
    }
}

//extrai uma sublista encadeada de uma lista encadeada.
list *create_sublist(list *L, int start, int end)
{
    if (L->head == NULL)
        return NULL;
    else
    {
        list *sublist = (list *)malloc(sizeof(list));
        sublist->head = NULL;
        sublist->size = 0;

        if (start < end)
        {
            node *aux = L->head;
            while (aux)
            {
                if (aux->indice > end)
                    break;
                if (aux->indice >= start && aux->indice <= end)
                    insere_fim(sublist, aux->valor);
                aux = aux->next;
            }
        }
        else
        {
            node *aux = L->head;
            while (aux->indice != start)
                aux = aux->next;
            while (aux)
            {
                if (aux->indice <= start && aux->indice >= end)
                    insere_fim(sublist, aux->valor);
                if (aux->indice < end)
                    break;
                aux = aux->prev;
            }
        }
        return sublist;
    }
}