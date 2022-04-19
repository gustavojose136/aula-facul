#include <stdlib.h>
#include <stdio.h>
#include <math.h>

	int main(void){
		float c, n1, n2, n3;
		printf("Escolha umas das opcoes:\n[ 1 ] Adicao\n[ 2 ] Subtracao\n[ 3 ] Multiplicacao\n[ 4 ] Divisao\n[ 5 ] Fim\n");
		scanf("%f", c);
		fflush(stdin);
		if(c==1){
			printf("Escolha um numero:\n");
			scanf("%f", n1);
			fflush(stdin);
			printf("Escolha outro numero:\n");
			scanf("%f", n2);
			fflush(stdin);
			n3=n1+n2;
			printf("A soma vai ser igual a:%f", n3);
		}
		
	}
