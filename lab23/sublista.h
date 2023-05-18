// Feito por Gabriel Canela, RA243453.
// Arquivo sublista.h

#ifndef SUBLISTA_H
#define SUBLISTA_H

// define os nós da lista.
typedef struct node
{
  int valor;
  int indice;
  struct node *next;
  struct node *prev;
} node;

// define a lista.
typedef struct list
{
  node *head;
  int size;
} list;

// função para alocar memória para a lista L, e define valores iniciais.
list *criar_lista();

// função para ler a primeira entrada, que define a lista inicial.
void ler_lista(list *L);

// função para criar um loop que executa os comando de entrada 's' e '+'.
void executar_comandos(list *L);

// função para inserir valores no fim da lista encadeada L.
void insere_fim(list *L, int valor);

// função para printar todos os valores da lista L.
void print_L(list *L);

// função para inserir uma sublsita na lista L, na posição indice.
void insere_sublista(list *L, list *sublist, int indice);

// função para criar uma sublista a partir de um intervalo [start..end] de uma lista L.
list *create_sublist(list *L, int start, int end);

// função para liberar a memória alocada pelos nós da lista.
void libera_lista(list *L);

#endif
