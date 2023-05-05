#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valor;
    struct node *proximo;
} Node;

void inserir_inicio(Node **inicio, int valor)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo)
    {
        novo->valor = valor;
        novo->proximo = *inicio;
        *inicio = novo;
    }
    else
        printf("Erro ao alocar memória.\n");
}

void inserir_fim(Node **inicio, int valor)
{
    Node *aux, *novo = (Node *)malloc(sizeof(Node));
    if (novo)
    {
        novo->valor = valor;
        novo->proximo = NULL;
        if (!*inicio)
        {
            *inicio = novo;
        }
        else
        {
            aux = *inicio;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memória.\n");
}

void inserir_meio(Node **inicio, int valor, int local)
{
    Node *aux, *novo = (Node *)malloc(sizeof(Node));
    if (novo)
    {
        novo->valor = valor;
        if (!*inicio)
        {
            novo->proximo = NULL;
            *inicio = novo;
        }
        else
        {
            aux = *inicio;
            while (aux->valor != local && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memória.\n");
}
void imprimir_lista(Node **lista){
    Node *aux = (Node *)malloc(sizeof(Node));
    if (aux){
    aux = *lista;
    if (!aux->proximo){
        printf('A lista está vazia!');
    }
    while(aux->proximo){
        print("%d",aux->valor);
        aux = aux->proximo;
    }
    } else
    printf("Erro ao alocar memória.\n");
}


int main(){


    return 0;
}