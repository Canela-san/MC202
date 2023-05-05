#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


#ifndef DEQUEF_H
#define DEQUEF_H

typedef struct {

  float* data;  // The array of floats.

  long first;  // The index of the first element in the deque.
  long size;   // The deque size.

  long cap;     // The array size.
  long mincap;  // The minimum array size.
  double factor;  // The resizing factor.

} dequef;


dequef* df_alloc(long capacity, double factor);
void df_free(dequef* D);

long df_size(dequef* A);

int df_push(dequef* D, float x);
float df_pop(dequef* D);

int df_inject(dequef* D, float x);
float df_eject(dequef* D);

void df_set(dequef* D, long i, float x);
float df_get(dequef* D, long i);

void df_print(dequef* A);

#endif


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
      df_free(d);     // Liberando a memória alocada para o dequef.
      return NULL; // Falha na alocação de memória.
   }
   d->first = 0;
   d->size = 0;
   d->cap = capacity;
   d->mincap = capacity;
   d->factor = factor;
   return d;
}

/**
  Apaga a o dequef e seus dados.
**/
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

void df_set(dequef *D, long i, float x)
{
   if (i < 0 || i >= D->size)
   {
      return;
   }

   D->data[(D->first + i) % D->cap] = x;
}

// retorna o valor
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

void df_print(dequef *D)
{
   printf("deque (%ld): ", D->size);
   for (long i = 0; i < D->size; i++)
   {
      printf("%.1f ", df_get(D, i));
   }
   printf("\n");
}



int main(void) {

  char cmd[13];
  float f;
  int i, st = 1;
  dequef* D = NULL;

  while (1) {
    scanf("%s",cmd);

    if (strcmp(cmd,"create") == 0) {
      scanf("%i %f",&i,&f);

      if (D != NULL)
        df_free(D);

      D = df_alloc(i,f);
      if (!D) {
        printf("Unable to create a dequef.\n");
        return errno ? errno : 1;
      }
    }

    else if (strcmp(cmd,"push") == 0) {
      scanf("%f",&f);
      st = df_push(D,f);
    }

    else if (strcmp(cmd,"pop") == 0) {
      if (df_size(D) > 0)
        f = df_pop(D);
    }

    else if (strcmp(cmd,"inject") == 0) {
      scanf("%f",&f);
      st = df_inject(D,f);
    }

    else if (strcmp(cmd,"eject") == 0) {
      if (df_size(D) > 0)
        f = df_eject(D);
    }

    else if (strcmp(cmd,"set") == 0) {
      scanf("%i %f",&i,&f);
      if (i >= 0 && i < df_size(D))
        df_set(D,i,f);
    }

    else if (strcmp(cmd,"get") == 0) {
      scanf("%i",&i);
      if (i >= 0 && i < df_size(D))
        printf("D[%d] == %.1f\n",i,df_get(D,i));
    }

    else if (strcmp(cmd,"is-empty?") == 0) {
      if (df_size(D) == 0)
        printf("empty\n");
      else
        printf("not empty\n");
    }

    else if (strcmp(cmd,"print") == 0) {
      df_print(D);
    }

    else if (strcmp(cmd,"exit") == 0) {
      df_free(D);
      return 0;
    }

    else {
      printf("Ups! invalid command: %s.\n",cmd);
      df_free(D);
      return 1;
    }

    if (st == 0) {
      printf("Unable to resize.");
      df_free(D);
      return errno ? errno : 1;
    }
  }
}
