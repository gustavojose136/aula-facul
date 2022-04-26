#include <stdlib.h>
#include <stdio.h>
#include <math.h>

	int main(void){
		float n1, n2, n3, m;
		printf("Digite sua primeira nota: \n");
		scanf("%f", &n1);
		fflush(stdin);
		printf("Digite sua segunda nota: \n");
		scanf("%f", &n2);
		fflush(stdin);
		printf("Digite sua terceira nota: \n");
		scanf("%f", &n3);
		fflush(stdin);
		m=(n1+n2+n3)/3;
		if ((n1<=-1 || n1>=11)||(n2<=-1 || n2>=11)||(n3<=-1 || n3>=11)){
			printf("Valor invalido");
		}	
		else if (m==10){
			printf("Aprovado com Distincao com media %.1f",m);
		}else if(m>=7){
			printf("Aprovado com media %.1f",m);
		}else if(m<7){
			printf("Reprovado com media %.1f",m);
		}
	}
