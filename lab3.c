#include <stdio.h>

int main() {
    int num1, num2;

    printf("Digite dois numeros inteiros separados por um espaco: ");
    scanf("%d %d", &num1, &num2);

    printf("Os numeros digitados foram %d e %d\n", num1, num2);

    return 0;
}