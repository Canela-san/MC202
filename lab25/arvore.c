#include <stdio.h>
#include "arvore.h"

Node *createTree(void)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Erro de locação de memória");
        return NULL;
    }
    node->k = NULL;
    node->name = NULL;
    node->pontos = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void inserir(Node *root, long int k, char name[], float pontos)
{
    Node *node = (Node *)malloc(sizeof(Node));
    Node *aux;
    if (node == NULL)
    {
        prinf("Memoria insuficiente");
        return;
    }
    node->k = k;
    node->name = name;
    node->pontos = pontos;
    node->left = NULL;
    node->right = NULL;
    aux = root;

    if (root->k == NULL)
    {
        root = node;
        free(aux);
        return NULL;
    }

    while (aux)
    {
        if (k < aux->k)
            aux = aux->left;
        if (k > aux->k)
            aux = aux->right;
        if (k == aux->k)
            return;
    }
    aux = node;
}
void remover(Node *root, long int k);
void buscar(long int k);
void imprimir(void);
void minimo(void);
void maximo(void);
void sucessor(long int k);
void predecessor(long int k);
void buscar_intervalo(long int k1, long int k2);