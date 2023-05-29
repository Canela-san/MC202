// Feito por Gabriel Canela, RA243453.
// Arquivo arvore.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "arvore.h"

Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int searchIndex(char arr[], int start, int end, char value)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}



Node* buildTree(char pre[], char in[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    Node* newNode = createNode(pre[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd)
        return newNode;

    int inIndex = searchIndex(in, inStart, inEnd, newNode->data);
    newNode->left = buildTree(pre, in, inStart, inIndex - 1, preIndex);
    newNode->right = buildTree(pre, in, inIndex + 1, inEnd, preIndex);

    return newNode;
}

Node *reconstruir_arvore(char pre[], char in[])
{
    int len = strlen(pre);
    int indice = 0;
    return buildTree(pre, in, 0, len - 1, &indice);
}

void PrintPosOrder(Node *node)
{
    if (node == NULL)
        return;

    PrintPosOrder(node->left);
    PrintPosOrder(node->right);
    printf("%c", node->data);
}

int getHeight(Node *node)
{
    if (node == NULL)
        return 0;

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

void printLevel(Node *node, int level)
{
    if (node == NULL)
        return;
    if (level == 1)
        printf("%c", node->data);
    else if (level > 1)
    {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
    }
}

void printTreeByLevel(Node *root)
{
    int height = getHeight(root);
    int i;

    for (i = 1; i <= height; i++)
    {
        printLevel(root, i);
    }
}

void freeTree(Node* root) {
    if (root == NULL)
        return;

    // Desaloca recursivamente os nós filhos
    freeTree(root->left);
    freeTree(root->right);

    // Desaloca o nó atual
    free(root);
}
