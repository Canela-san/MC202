
#ifndef STRUCT_H
#define STRUCT_H

typedef struct node
{
  char *name;
  struct node *next;
  struct node *prev;

} node;

typedef struct list
{
  node *head;
  node *indicator;
} list;

// void Lcreate(void);

void Linsert(list *L, char nome[150]);

void Lremove(list *L, char nome[150]);

int Lplay(list *L);

void Lgo_back(list *L);

void Lfinal(list *L);

void Linvert(list *L);

void Lfree(list *L);

#endif
