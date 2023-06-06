#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"


void inserir(Node **root, long int k, char name[], float pontos)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Memoria insuficiente");
        return;
    }
    else
    {
        node->k = k;
        strcpy(node->name, name);
        node->pontos = pontos;
        node->left = NULL;
        node->right = NULL;

        if (*root == NULL)
        {
            *root = node;
        }
        else
        {
            Node *aux = *root;
            while (1)
            {
                if (k < aux->k)
                {
                    if (aux->left == NULL)
                    {
                        aux->left = node;
                        break;
                    }
                    else
                    {
                        aux = aux->left;
                    }
                }
                else if (k > aux->k)
                {
                    if (aux->right == NULL)
                    {
                        aux->right = node;
                        break;
                    }
                    else
                    {
                        aux = aux->right;
                    }
                }
                else if (k == aux->k)
                {
                    free(node);
                    return;
                }
            }
        }
    }
}
void remover(Node *root, long int k)
{
    Node *aux, *aux2;
    if (&(root->k) == NULL)
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
    if (&(root->k) == NULL)
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
void imprimir(Node *root)
{
    if (!root)
        return;
    imprimir(root->left);
    printf("-%s (%ld)-", root->name, root->k);
    imprimir(root->right);
}
Node *minimo(Node **root)
{
    while ((*root)->left != NULL)
        *root = (*root)->left;
    return *root;
}
Node *maximo(Node **root)
{
    while ((*root)->right != NULL)
        *root = (*root)->right;
    return *root;
}
Node *sucessor(Node *root, long int k)
{
    Node *aux = (buscar(root, k))->right;
    while (aux->left)
        aux = aux->left;
    return aux;
}
Node *predecessor(Node *root, long int k)
{
    Node *aux = (buscar(root, k))->left;
    while (aux->right)
        aux = aux->right;
    return aux;
}
// void buscar_intervalo(Node *root, long int k1, long int k2){
// printf("%ld", k1);
// imprimir(buscar(root, k1)->right);
// }
void free_tree(Node *root);