#include <stdio.h>

int main()
{
    int dano, ryu, ken, count_ryu = 0, count_ken = 0;
    scanf("%d", &ryu);
    scanf("%d", &ken);
    while (ryu > 0 && ken > 0) {

	scanf("%d", &dano);

	if (dano > 0) {
	    ken -= dano;
	    count_ryu++;
	    if (ken < 0) {
		ken = 0;
	    }

	    printf("RYU APLICOU UM GOLPE: %d\n", dano);
	} else {
	    dano = -1 * dano;
	    ryu -= dano;
	    count_ken++;
	    if (ryu < 0) {
		ryu = 0;
	    }
	    printf("KEN APLICOU UM GOLPE: %d\n", dano);
	}

	printf("HP RYU = %d\n", ryu);
	printf("HP KEN = %d\n", ken);

    }
    if (ryu > ken) {
	printf("LUTADOR VENCEDOR: RYU\n");
    } else {
	printf("LUTADOR VENCEDOR: KEN\n");
    }
    printf("GOLPES RYU = %d\n", count_ryu);
    printf("GOLPES KEN = %d\n", count_ken);
    return 0;
}