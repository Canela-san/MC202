// Feito por Gabriel Canela, RA243453.
// Arquivo arvore.h

#ifndef ARVORE_H
#define ARVORE_H

// define os nós da árvore.

typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(char data);
Node *reconstruir_arvore(char pre[], char in[]);
Node *buildTree(char pre[], char in[], int inStart, int inEnd, int *preIndex);
int getHeight(Node *node);
int searchIndex(char arr[], int start, int end, char value);
void PrintPosOrder(Node *node);
void printTreeByLevel(Node *root);
void printLevel(Node *node, int level);
void freeTree(Node *root);

#endif