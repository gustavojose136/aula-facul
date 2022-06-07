#include <stdio.h>
#include <stdlib.h>

	int main(void){
		float n[4];
		int i;
		
		for(i=0;i<=4;i++){
			printf("Digite o %i numero: \n",i+1);
			scanf("%f", &n[i]);
			fflush(stdin);
		}
		printf("Os numeros digitados sao: %.1f, %.1f, %.1f, %.1f, %.1f \n",n[0], n[1], n[2], n[3], n[4]);
		printf("A soma dos numeros digitados sera: %.1f \n",n[0]+n[1]+n[2]+n[3]+n[4]);
		printf("A multiplicacao dos numeros digitados sera: %.1f",n[0]*n[1]*n[2]*n[3]*n[4]);
	}
