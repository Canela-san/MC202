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
    strcpy(node->name, name);
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
void remover(Node *root, long int k)
{
    Node *aux, *aux2;
    if (root->k == NULL)
        return;
    if (k < root->k)
        root = root->left;
    if (k > root->k)
        root = root->right;
    if (k == root->k)
    {
        if (root->left == NULL)
        {
            aux = root->right;
            free(root);
            return;
        }
        if (root->right == NULL)
        {
            aux = root->left;
            free(root);
            return;
        }
        aux2 = root->left;
        while (aux2->right != NULL)
            aux2 = aux2->right;
        root->k = aux2->k;
        root->left = aux2->left;
        root->right = aux2->right;
        free(aux2);
        return;
    }
    remover(root->left, k);
    remover(root->right, k);
    return;
}

Node *buscar(Node *root, long int k)
{
    Node *aux = root;
    if (root->k == NULL)
    {
        printf("Nenhum registro encontrado\n");
    }
    else
    {
        while (aux)
        {
            if (k < aux->k)
            {
                aux = aux->left;
            }
            else if (k > aux->k)
            {
                aux = aux->right;
            }
            if (k == aux->k)
            {
                return aux;
            }
        }
    }
    return NULL;
}
void imprimir(Node *root){
    Node *aux = root;
    imprimir(aux->left);
    printf("%s", aux->name);
    imprimir(aux->right);
}
Node *minimo(Node **root){
    while(*root->left != NULL)
        root = *root->left;
    return root;
}
Node *maximo(Node **root){
        while(*root->right != NULL)
        root = *root->right;
    return root;
}
Node *sucessor(Node *root, long int k){
    Node *aux = (buscar(root, k))->right;
    while(aux->left)
        aux = aux->left;
    return aux;
}
Node *predecessor(Node *root, long int k){
    Node *aux = (buscar(root, k))->left;
    while(aux->right)
        aux = aux->right;
    return aux;
}
void buscar_intervalo(Node *root, long int k1, long int k2);
printf("%d", k1);
imprimir(buscar(root, k1->right));
void free_tree(Node *root)
{
}