#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

Node *createTree(void)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Erro de locação de memória");
        return NULL;
    }
    node->left = NULL;
    node->right = NULL;
    node->k = 0;
    strcpy(node->name, "");
    return node;
}
Node *inserir(Node *root, long int k, char name[], float pontos)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Memoria insuficiente");
        return root;
    }

    node->k = k;
    strcpy(node->name, name);
    node->pontos = pontos;
    node->left = NULL;
    node->right = NULL;

    if ((root->k == 0) && (root->pontos == 0))
    {
        return node;
    }

    Node *aux = root;
    Node *anterior = NULL;
    while (aux != NULL)
    {
        anterior = aux;
        if (k < aux->k)
            aux = aux->left;
        else if (k > aux->k)
            aux = aux->right;
        else
            return root;
    }
    if (k < anterior->k)
        anterior->left = node;
    else
        anterior->right = node;
    return root;
}
void remover(Node *root, long int k);
void buscar(Node *root, long int k);
void imprimir(Node *root)
{
    if (root == NULL)
        return;
    Node *aux = root;
    imprimir(aux->left);
    printf("k='%ld', nome='%s', pontos:'%f'\n", aux->k, aux->name, aux->pontos);
    imprimir(aux->right);
}
void minimo(Node *root);
void maximo(Node *root);
void sucessor(Node *root, long int k);
void predecessor(Node *root, long int k);
void buscar_intervalo(Node *root, long int k1, long int k2);
void free_tree(Node *root)
{
}