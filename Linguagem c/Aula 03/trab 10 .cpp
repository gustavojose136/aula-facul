#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
	float n1, n2, a;
	printf("Digite quantos voce ganha por hora: \n");
	scanf("%f", &n1);
	fflush(stdin);
	printf("Digite quantas horas voce trabalha no mes: \n");
	scanf("%f", &n2);
	fflush(stdin);
	a= n1*n2;
	printf("Voce ganhou:%.1f neste mes", a);
	

}
