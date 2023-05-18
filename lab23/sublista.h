
#ifndef SUBLISTA_H
#define SUBLISTA_H

typedef struct node
{
  int valor;
  int indice;
  struct node *next;
  struct node *prev;
} node;

typedef struct list
{
  node *head;
  int size;
} list;

void ler_lista(list *L);

void executar_comandos(list *L);

void insere_fim(list *L, int valor);

void print_L(list *L);

void insere_sublista(list *L, list *sublist, int indice);

list *create_sublist(list *L, int start, int end);

void libera_lista(list *L);

#endif
