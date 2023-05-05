#include <stdio.h>

int MenorValor(int vetor[], int tamanho) // encontra o valor mínimo de um vetor
{
    int local = 0; // Inicializa com o primeiro elemento do vetor
    for (int i = 1; i < tamanho; i++)
    { // Percorre os demais elementos do vetor
        if (vetor[i] < vetor[local])
        {              // Se o elemento atual for menor que o valor mínimo encontrado até agora
            local = i; // Atualiza o valor mínimo
        }
    }
    return local;
}

int main()
{
    int C, N, T, D, temp = 0, result = 0;
    scanf("%d %d", &C, &N);
    int cv[C];
    for (int i = 0; i < C; i++) // Inicializa cada elemento do vetor com valor 0
    { 
        cv[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &T, &D);
        temp = MenorValor(cv, C);
        if (cv[temp] >= T)
        {
            if ((cv[temp] - T) > 20)
            {
                result++;
            }
            cv[temp] += D;
        }
        else
        {
            cv[temp] = T + D;
        }
    }
    printf("%d\n", result);
    return 0;
}