#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void inserir(Node **root, long int k, char name[], float pontos)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("memoria insuficiente");
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
Node *removeNode(Node *root, long int k)
{
    Node *current = root;
    Node *parent = NULL;
    int isLeftChild = 0;

    while (current != NULL && current->k != k)
    {
        parent = current;
        if (k < current->k)
        {
            current = current->left;
            isLeftChild = 1;
        }
        else
        {
            current = current->right;
            isLeftChild = 0;
        }
    }

    if (current == NULL)
        return root;

    if (current->left == NULL && current->right == NULL)
    {
        if (current == root)
        {
            free(root);
            return NULL;
        }

        if (isLeftChild)
            parent->left = NULL;
        else
            parent->right = NULL;

        free(current);
    }
    else if (current->left == NULL)
    {
        if (current == root)
        {
            root = current->right;
            free(current);
            return root;
        }

        if (isLeftChild)
            parent->left = current->right;
        else
            parent->right = current->right;

        free(current);
    }
    else if (current->right == NULL)
    {
        if (current == root)
        {
            root = current->left;
            free(current);
            return root;
        }

        if (isLeftChild)
            parent->left = current->left;
        else
            parent->right = current->left;

        free(current);
    }
    else
    {
        Node *successor = minimo(current->right);
        current->k = successor->k;
        strcpy(current->name, successor->name);
        current->pontos = successor->pontos;
        current->right = removeNode(current->right, successor->k);
    }

    return root;
}
Node *buscar(Node *root, long int k)
{
    Node *aux = root;
    if (root == NULL)
        printf("nao ha cliente %ld\n", k);
    else
    {
        while (aux)
        {
            if (k < aux->k)
            {
                if (aux->left)
                    aux = aux->left;
                else
                    return NULL;
            }
            else if (k > aux->k)
            {
                if (aux->right)
                    aux = aux->right;
                else
                    return NULL;
            }
            if (k == aux->k)
                return aux;
        }
    }
    return NULL;
}
void imprimir(Node *root)
{
    if (!root)
        return;
    imprimir(root->left);
    printf("%s (%ld) ", root->name, root->k);
    imprimir(root->right);
}
Node *minimo(Node *root)
{
    if (!root)
        return NULL;
    Node *aux = root;
    while (aux->left != NULL)
        aux = aux->left;
    return aux;
}
Node *maximo(Node *root)
{
    if (!root)
        return NULL;
    Node *aux = root;
    while (aux->right != NULL)
        aux = aux->right;
    return aux;
}
Node *sucessor(Node *root, long int k)
{
    Node *current = root;
    Node *successor = NULL;

    while (current != NULL)
    {
        if (current->k == k)
        {
            if (current->right != NULL)
            {
                successor = minimo(current->right);
            }
            break;
        }
        else if (current->k > k)
        {
            successor = current;
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    return successor;
}
Node *predecessor(Node *root, long int k)
{
    Node *current = root;
    Node *predecessor = NULL;

    while (current != NULL)
    {
        if (current->k == k)
        {
            if (current->left != NULL)
            {
                predecessor = maximo(current->left);
            }
            break;
        }
        else if (current->k > k)
        {
            current = current->left;
        }
        else
        {
            predecessor = current;
            current = current->right;
        }
    }

    return predecessor;
}
void imprimir_intervalo(Node *root, long int k1, long int k2, int *temp)
{
    if (root == NULL)
        return;

    if (root->k > k1)
        imprimir_intervalo(root->left, k1, k2, temp);

    if (root->k >= k1 && root->k <= k2)
    {
        *temp = 1;
        printf("%ld ", root->k);
    }

    if (root->k < k2)
        imprimir_intervalo(root->right, k1, k2, temp);
}
void freeTree(Node *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}