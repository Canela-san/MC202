#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "dequef.h"

dequef *df_alloc(long capacity, double factor)
{
   dequef *d = (dequef *)malloc(sizeof(dequef)); // Alocando a memória para o dequef.
   if (d == NULL)
   {
      return NULL; // Falha na alocação de memória.
   }
   d->data = (float *)malloc(capacity * sizeof(float)); // Alocando a memória para o array de floats.
   if (d->data == NULL)
   {
      free(d);     // Liberando a memória alocada para o dequef.
      return NULL; // Falha na alocação de memória.
   }
   //define os valores iniciais oara o dequef
   d->first = 0;
   d->size = 0;
   d->cap = capacity;
   d->mincap = capacity;
   d->factor = factor;
   return d;
}

// Apaga a o dequef e seus dados.
void df_free(dequef *D)
{
   free(D->data); // libera o array de floats
   free(D);       // libera a struct dequef
}

// retorna a quantidade de dados no deque
long df_size(dequef *D)
{
   return D->size;
}

// modifica o tamanho da memória alocada para os dados do deque
int df_resize(dequef *D, long new_cap)
{
   if (new_cap < D->size || new_cap < D->mincap)
      return 0;

   float *new_data = (float *)realloc(D->data, new_cap * sizeof(float));
   if (!new_data)
      return 0;
   D->data = new_data;
   D->cap = new_cap;

   return 1;
}

// insere um valor x no final dos dados do deque
int df_push(dequef *D, float x)
{
   if (D->size == D->cap)
   {
      long new_cap = D->cap * D->factor;
      if (!df_resize(D, new_cap))
         return 0;
   }

   long last = (D->first + D->size) % D->cap;
   D->data[last] = x;
   D->size++;

   return 1;
}
// remove o ultimo dado do deque
float df_pop(dequef *D)
{
   if (D->size == 0)
      return 0.0;

   long last = (D->first + D->size - 1) % D->cap;
   float x = D->data[last];
   D->size--;

   if (D->cap / (D->factor * D->factor) >= D->size && D->cap / D->factor >= D->mincap)
   {
      long new_cap = D->cap / D->factor;
      df_resize(D, new_cap);
   }

   return x;
}

// insere um valor x no início dos dados do deque
int df_inject(dequef *D, float x)
{
   if (D->size == D->cap)
   {
      long new_cap = D->cap * D->factor;
      if (!df_resize(D, new_cap))
      {
         return 0;
      }
   }

   D->first = (D->first - 1 + D->cap) % D->cap;
   D->data[D->first] = x;
   D->size++;

   return 1;
}


// remove um valor x no início dos dados do deque
float df_eject(dequef *D)
{
   if (D->size == 0)
   {
      return 0.0;
   }
   else
   {

      float x = D->data[D->first];
      D->first = (D->first + 1) % D->cap;
      D->size--;

      if (D->size <= D->cap / (D->factor * D->factor))
      {
         long new_cap = D->cap / D->factor;
         if (new_cap < D->mincap)
         {
            new_cap = D->mincap;
         }

         if (!df_resize(D, new_cap))
         {
            return x;
         }
      }

      return x;
   }
}

// modifica o valor do elemento na posição i para x
void df_set(dequef *D, long i, float x)
{
   if (i < 0 || i >= D->size)
   {
      return;
   }

   D->data[(D->first + i) % D->cap] = x;
}

// retorna o valor na posição i
float df_get(dequef *D, long i)
{
   if (i >= 0 && i < D->size)
   {
      return D->data[(D->first + i) % D->cap];
   }
   else
   {
      return 0;
   }
}

// printa todos os dados do deque
void df_print(dequef *D)
{
   printf("deque (%ld): ", D->size);
   for (long i = 0; i < D->size; i++)
   {
      printf("%.1f ", df_get(D, i));
   }
   printf("\n");
}
