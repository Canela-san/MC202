#include <stdio.h>
#include <stdlib.h>
#include "sublista.h"

// Função para ler a lista a partir da entrada padrão e inserir os elementos na lista encadeada L
void ler_lista(list *L)
{
    int start, temp;
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
    // Libera os caracteres a mais no stdinput '} '.
    getchar();
    getchar();
}

// Função principal que lê os comandos e executa as operações na lista encadeada
void executar_comandos(list *L)
{
    char comando;
    int start, end, indice;

    while (1)
    {
        scanf("%c", &comando);
        if (comando == 'f')
            break;

        if (comando == 's')
        {
            scanf(" A[%d..%d]", &start, &end);
            L = create_sublist(L, start, end);
            print_L(L);
        }
        else if (comando == '+')
        {
            scanf(" A[%d..%d] %d", &start, &end, &indice);
            list *sublist = create_sublist(L, start, end);
            insere_sublista(L, sublist, indice);
            print_L(L);
        }
    }
}

void insere_fim(list *L, int valor)
{
    int indice = 0;
    node *novo = calloc(1, sizeof(node));
    if (novo == NULL)
    {
        printf("Erro na alocação de memória\n");
        return;
    }

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

void insere_sublista(list *L, list *sublist, int indice)
{
    if (L->head == NULL || sublist->head == NULL)
        return;

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
        if (indice)
        {
            while (aux1->indice != indice)
                aux1 = aux1->next;

            while (aux2->next != NULL)
                aux2 = aux2->next;

            aux1->prev->next = sublist->head;
            sublist->head->prev = aux1->prev;
            aux2->next = aux1;
            aux1->prev = aux2;
        }
        else
        {
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

list *create_sublist(list *L, int start, int end)
{
    if (L->head == NULL)
        return NULL;

    list *sublist = calloc(1, sizeof(list));
    if (sublist == NULL)
    {
        printf("Erro na alocação de memória\n");
        return NULL;
    }

    sublist->head = NULL;
    sublist->size = 0;
    node *aux = L->head;

    if (start < end)
    {
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

// Função para apagar listas
void libera_lista(list *L)
{
    if (L == NULL)
        return;

    node *aux = L->head;
    while (aux)
    {
        node *temp = aux;
        aux = aux->next;
        free(temp);
    }

    L->head = NULL;
    L->size = 0;
    free(L);
}