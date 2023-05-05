#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
    int valor;
} Coordenada;

int compararCoordenadas(const void *a, const void *b)
{
    Coordenada *coordA = (Coordenada *)a;
    Coordenada *coordB = (Coordenada *)b;

    if (coordA->x != coordB->x)
    {
        return coordA->x - coordB->x;
    }
    else if (coordA->y != coordB->y)
    {
        return coordA->y - coordB->y;
    }
    else
    {
        return coordA->valor - coordB->valor;
    }
}

Coordenada *adicionarCoordenada(Coordenada *vc, int *quant, int x, int y, int valor)
{
    vc[*quant].x = x;
    vc[*quant].y = y;
    vc[*quant].valor = valor;
    (*quant)++;
    qsort(vc, *quant, sizeof(Coordenada), compararCoordenadas);
    return vc;
}

Coordenada *removerCoordenada(Coordenada *vc, int *quant, int x, int y)
{
    for (int i = 0; i < *quant; i++)
    {
        if (vc[i].x == x && vc[i].y == y)
        {
            vc[i].valor = 0;
            break;
        }
    }
    qsort(vc, *quant, sizeof(Coordenada), compararCoordenadas);
    (*quant)--;
    return vc;
}

void imprimirCoordenadas(Coordenada *vc, int quant)
{
    printf("VC: ");
    for (int i = 0; i < quant; i++)
    {
        printf("(%d,%d,%d) ", vc[i].x, vc[i].y, vc[i].valor);
    }
    printf("\n");
}

int main()
{
    int num1, num2, k, n;
    scanf("%d %d %d", &num1, &num2, &k);
    Coordenada *vc = malloc((num1 + num2) * sizeof(Coordenada));
    int quant = 0;

    int **matriz = malloc(num1 * sizeof(int *));
    for (int i = 0; i < num1; i++)
    {
        matriz[i] = calloc(num2, sizeof(int));
    }

    int x, y, valor;
    char c;
    while (k--)
    {
        scanf(" [%d,%d] %d", &x, &y, &valor);
        matriz[x][y] = valor;
        vc = adicionarCoordenada(vc, &quant, x, y, valor);
    }

    while (1)
    {
        scanf(" %c", &c);
        if (c == 't')
            break;

        if (c == 'p')
        {
            if (quant == 0)
            {
                printf("O VC esta' vazio.\n");
            }
            else
            {
                imprimirCoordenadas(vc, quant);
            }
        }
        else
        {
            scanf(" [%d,%d]", &x, &y);
            if (c == 'r')
            {
                printf("M[%d][%d] == %d\n", x, y, matriz[x][y]);
            }
            else if (c == 'a')
            {
                scanf(" %d", &valor);
                matriz[x][y] += valor;
                if (matriz[x][y] != 0)
                {
                    vc = adicionarCoordenada(vc, &quant, x, y, matriz[x][y]);
                }
                else
                {
                    vc = removerCoordenada(vc, &quant, x, y);
                }
            }
            else if (c == 'c')
            {
                scanf(" %d", &valor);
                if (valor == 0)
                {
                    vc = removerCoordenada(vc, &quant, x, y);
                }
                else
                {
                    matriz[x][y] = valor;
                    if (quant == 0)
                    {
                        vc = adicionarCoordenada(vc, &quant, x, y, valor);
                    }
                    else
                    {
                        int i;
                        for (i = 0; i < quant; i++)
                        {
                            if (vc[i].x == x && vc[i].y == y)
                            {
                                vc[i].valor = valor;
                                break;
                            }
                        }
                        if (i == quant)
                        {
                            vc = adicionarCoordenada(vc, &quant, x, y, valor);
                        }
                    }
                }
            }
        }
    }
    return 0;
}