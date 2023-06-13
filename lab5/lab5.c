#include <stdio.h>
#include <stdlib.h>

int **VetorShort(int **Vetor, int quant)
{
    quant -= 1;
    for (int i = 0; i < quant + 1; i++)
    {
        for (int j = i + 1; j < quant + 1; j++)
        {
            if (Vetor[j][0] < Vetor[i][0])
            {
                for (int k = 0; k < 3; k++)
                {
                    int temp = Vetor[i][k];
                    Vetor[i][k] = Vetor[j][k];
                    Vetor[j][k] = temp;
                }
            }
            else if (Vetor[j][0] == Vetor[i][0])
            {
                if (Vetor[j][1] < Vetor[i][1])
                {
                    for (int l = 0; l < 3; l++)
                    {
                        int temp = Vetor[i][l];
                        Vetor[i][l] = Vetor[j][l];
                        Vetor[j][l] = temp;
                    }
                }
            }
        }
    }
    return Vetor;
}

int **AddVetor(int **original, int x, int y, int valor, int quant)
{
    original[quant][0] = x;
    original[quant][1] = y;
    original[quant][2] = valor;
    return VetorShort(original, quant);
}

int **RmVetor(int **original, int x, int y, int quant)
{
    int temp = 0;
    quant -= 1;
    for (int i = 0; i < quant; i++)
    {
        if ((temp) && (i != quant))
        {
            original[i][0] = original[i + 1][0];
            original[i][1] = original[i + 1][1];
            original[i][2] = original[i + 1][2];
        }
        else if ((original[i][0] == x) && (original[i][1] == y))
        {
            temp = 1;
            original[i][2] = 0;
            i -= 1;
        }
    }

    return original;
}

int main()
{
    int num1, num2, k, n, vetor[2];
    int quant = 0;
    int **matriz;
    scanf("%d %d", &num1, &num2);
    int tamanho = num1 + num2;
    int **vetorcoor = (int **)malloc(tamanho * sizeof(int *)); // aloca as linhas da matriz
    for (int i = 0; i < tamanho; i++)
    {
        vetorcoor[i] = (int *)malloc(3 * sizeof(int)); // aloca as colunas de cada linha
    }
    scanf("%d", &k);

    matriz = (int **)malloc(num1 * sizeof(int *)); // aloca as linhas da matriz
    for (int i = 0; i < num1; i++)
    {
        matriz[i] = (int *)malloc(num2 * sizeof(int)); // aloca as colunas de cada linha
    }

    for (int i = 0; i < num1; i++) // coloca 0 em todos os campos da matriz
    {
        for (int j = 0; j < num2; j++)
        {
            matriz[i][j] = 0;
        }
    }
    while (getchar() != '\n')
        ;
    int j = 0;
    while (j < k)
    {

        scanf("[%d,%d] %d", &vetor[0], &vetor[1], &n);
        matriz[vetor[0]][vetor[1]] = n;
        while (getchar() != '\n')
            ;
        vetorcoor[j][0] = vetor[0];
        vetorcoor[j][1] = vetor[1];
        vetorcoor[j][2] = n;
        quant++;
        j++;
    }

    int x, y, b;
    char a;
    while (1)
    {
        int n = scanf("%c", &a); // lê o primeiro char
        if (a == 't')
        {
            break;
        }
        if (a == 'p')
        {
            if (quant == 0)
            {
                printf("O VC esta' vazio.\n");
            }
            else
            {
                vetorcoor = VetorShort(vetorcoor, quant);
                printf("VC: ");
                for (int i = 0; i < quant; i++)
                {
                    printf("(%d,%d,%d) ", vetorcoor[i][0], vetorcoor[i][1], vetorcoor[i][2]);
                }
                printf("\n");
            }
        }
        else
        {

            n = scanf(" [%d,%d]", &x, &y); // tenta ler os valores de x e y
            if (n != 2)
            { // se não houver dois valores lidos, assume que não há x e y
                x = y = 0;
            }
            else
            {
                if (a == 'r')
                {
                    printf("M[%d][%d] == %d\n", x, y, matriz[x][y]);
                }
                else
                {
                    n = scanf(" %d", &b); // tenta ler o valor de b
                    if (n != 1)
                    { // se não houver valor lido, assume que não há b
                        b = 0;
                    }
                    else
                    {

                        if ((matriz[x][y] == 0) && (b != 0))
                        {
                            if (quant == (num1 + num2))
                            {
                                printf("O VC esta' cheio.\n");
                            }
                            else
                            {
                                matriz[x][y] = b;
                                vetorcoor = AddVetor(vetorcoor, x, y, b, quant);
                                quant++;
                            }
                        }
                        else
                        {
                            if ((matriz[x][y] != 0) && (b == 0))
                            {
                                vetorcoor = RmVetor(vetorcoor, x, y, quant);
                                quant -= 1;
                            }
                            matriz[x][y] = b;
                            for (int i = 0; i < quant; i++)
                            {
                                if ((vetorcoor[i][0] == x) && (vetorcoor[i][1] == y))
                                {
                                    vetorcoor[i][2] = b;
                                }
                            }
                        }
                    }
                }
            }
        }
        while (getchar() != '\n')
            ;
    }
    return 0;
}