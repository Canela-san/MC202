#include <stdio.h>

#include "struct.h"
#include "struct.c"

int main()
{

    int temp, entrada;

    while (TRUE)
    {
        scanf("%d", &temp);
if (temp == 0){break;}

        scanf("%d", &entrada);
        printf("%d\n", entrada);
        temp--;
    }

    return 0;
}