/**
  list.h
  Declarations for a deque of floats stored in a dynamic array.
**/


#ifndef STRUCT_H
#define STRUCT_H

typedef struct node{

    char* name;
    node* next;
    node* prev;

} node;

typedef struct list{
node* head;
node* indicator;
} list;


node* create();

void insert(list* L, char nome[100]);

void remove(list* L, char nome[100]);

void play(list* L);

void go_back(list* L);

void final(list* L);

void invert(list* L);

#endif
