
#ifndef STRUCT_H
#define STRUCT_H

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

void insere_fim(list *L, int valor);

void all_print(list *L);

void insere_sublista(list *L, list *sublist, int indice);

list *create_sublist(list *L, int start, int end);

#endif
