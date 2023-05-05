#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valor;
    struct node *proximo;
} Node;

void imprimir(Node **inicio)
{
    Node *aux;
    aux = *inicio;
    while (aux->proximo != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

void inserir_inicio(Node **inicio, int valor)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo)
    {
        novo->valor = valor;

        if (!*inicio)
        {
            novo->proximo = NULL;
        }
        else
        {
            novo->proximo = *inicio;
            *inicio = novo;
        }
    }
    else
        printf("Erro ao alocar memória.\n");
}

int main()
{
    Node *lista = (Node *)malloc(sizeof(Node));
    lista->valor = 6;
    lista->proximo = NULL;
    inserir_inicio(&lista, 5);
    inserir_inicio(&lista, 6);
    inserir_inicio(&lista, 7);
    inserir_inicio(&lista, 5);
    inserir_inicio(&lista, 6);
    inserir_inicio(&lista, 7);
    inserir_inicio(&lista, 5);
    inserir_inicio(&lista, 6);
    inserir_inicio(&lista, 7);
    inserir_inicio(&lista, 6);

    imprimir(&lista);
    remover(&lista, 6);
    imprimir(&lista);
    return 0;
}

void remover(Node **lista, int valor)
{
    Node *aux, *aux2 = (Node *)malloc(sizeof(Node));

    aux2 = *lista;
    aux = aux2->proximo;
    while (aux->proximo)
    {
        if (aux->valor == valor)
        {
            aux2->proximo = aux->proximo;
            aux2 = aux->proximo;
            aux = aux2->proximo;
        }
        else
        {
            aux = aux->proximo;
            aux2 = aux2->proximo;
        }
    }
    aux = *lista;
    if (aux->valor == valor)
    {
        *lista = aux->proximo;
    }
}


void duplicate(Node **lista, Node **copia){
    Node *aux = (Node *)malloc(sizeof(Node));
    aux = *lista;
    while(aux->proximo){
        Node *aux2 = (Node *)malloc(sizeof(Node));
        *copia
    }
    
}