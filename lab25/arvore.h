// Feito por Gabriel Canela, RA243453.
// Arquivo arvore.h

#ifndef ARVORE_H
#define ARVORE_H

// define os nós da árvore.

typedef struct Node
{
    long int k;
    char name[];
    float pontos;
    struct Node *left;
    struct Node *right;
} Node;

Node *createTree(void);
void inserir(Node *root, long int k, char nome[], float pontos);
void remover(Node *root, long int k);
void buscar(long int k);
void imprimir(void);
void minimo(void);
void maximo(void);
void sucessor(long int k);
void predecessor(long int k);
void buscar_intervalo(long int k1, long int k2);

#endif