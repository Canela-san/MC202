// Feito por Gabriel Canela, RA243453.
// Arquivo arvore.h

#define NAME_SIZE 101
#define COMMAND_SIZE 18

#ifndef ARVORE_H
#define ARVORE_H

// paremetros:
//  define os nós da árvore.
typedef struct Node
{
    long int k;
    char name[NAME_SIZE];
    float pontos;
    struct Node *left;
    struct Node *right;
} Node;

void inserir(Node **root, long int k, char name[], float pontos);         // insere um nó na arvore
Node *removeNode(Node *root, long int k);                                 // remove um nó da arvore
Node *buscar(Node *root, long int k);                                     // busca um nó na arvore
void imprimir(Node *root);                                                // imprime todos os nós da arvore em-ordem
Node *minimo(Node *root);                                                 // encontra o nó com menor chave
Node *maximo(Node *root);                                                 // encontra o nó com maior chave
Node *sucessor(Node *root, long int k);                                   // encontra o primeiro nó com valor maior que K
Node *predecessor(Node *root, long int k);                                // encontra o primeiro nó com valor menor que K
void imprimir_intervalo(Node *root, long int k1, long int k2, int *temp); // imprime nós que tem valor dentro do intervalo
void freeTree(Node *root);                                                // executa free para todos os nós da arvore

#endif
