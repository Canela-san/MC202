// Feito por Gabriel Canela, RA243453.
// Arquivo arvore.h

#define NAME_SIZE 100
#define COMMAND_SIZE 100


#ifndef ARVORE_H
#define ARVORE_H

//paremetros:
// define os nós da árvore.
typedef struct Node
{
    long int k;
    char name[NAME_SIZE];
    float pontos;
    struct Node *left;
    struct Node *right;
} Node;

Node *createTree();
Node *inserir(Node *root, long int k, char nome[], float pontos);
void remover(Node *root, long int k);
void buscar(Node *root, long int k);
void imprimir(Node *root);
void minimo(Node *root);
void maximo(Node *root);
void sucessor(Node *root, long int k);
void predecessor(Node *root, long int k);
void buscar_intervalo(Node *root, long int k1, long int k2);
void free_tree(Node *root);

#endif