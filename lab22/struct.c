#include <stdio.h>
#include <string.h>

node *create(long capacity, double factor)
{
    list *L = (list *)malloc(sizeof(list));
    L->head = NULL;
    L->indicator = NULL;
}

void insert(list *L, char nome[100])
{
    node *no = (node *)malloc(sizeof(node));
    no->name = (char *)malloc(sizeof(char) * 100);
    strcpy(no->name, nome);
    if (L->head == NULL)
    {
        L->head = no;
        L->indicator = no;
        no->prev, no->next = NULL;
    }
    else
    {
        no->prev = L->indicator;
        no->next = L->indicator->next;
        L->indicator->next = no;
    }
}

void remove(list *L, char name[100])
{
    node *lixo;
    node *aux = (node *)malloc(sizeof(node));
    aux = L->head;

    while (aux->next && aux->name != name)
    {
        aux = aux->next;
    }
    if (aux->name == name)
    {
        lixo = aux;
        if (L->head == aux)
        {
            L->head = lixo->next;
            L->head->prev = NULL;
            if (L->indicator == lixo)
            {
                L->indicator = lixo->next;
            }
        }
        else
        {
            lixo->prev->next = lixo->next;
            lixo->next->prev = lixo->prev;
        }
        free(lixo);
    }
}
void play(list *L)
{
    if (L->indicator->next != NULL)
        L->indicator = L->indicator->next;
}

void go_back(list *L)
{
    if (L->indicator->prev != NULL)
        L->indicator = L->indicator->prev;
}

void final(list *L)
{
    node *aux;
    aux = L->head;
    while (aux->next)
    {
        aux = aux->next;
    }
    L->indicator = aux;
}

void invert(list *L)
{
    if ((L->head == NULL) || (L->head->next == NULL))
        return;

    node *atual, *aux = (node *)malloc(sizeof(node));

    atual = L->head;

    while (atual)
    {
        aux = atual->prev;
        atual->prev = atual->next;
        atual->next = aux;
        atual = atual->prev;
    }
}