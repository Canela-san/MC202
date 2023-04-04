#include <stdio.h>

int diferenca(int a, int b)
{
    return a - b;
}

int main()
{
    int num1, num2, dif;
    scanf("%d", &num1);
    scanf("%d", &num2);
    dif = diferenca(num1, num2);
    printf("%d\n", dif);

    return 0;
}