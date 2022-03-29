#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main (void){
	float n1, a, p=3.14;
	printf("Vamos calcular a area do ciculo, digite o raio: \n");
	scanf("%f", &n1);
	fflush(stdin);
	a = p*n1*n1;
	printf("Sua area e: %.1f", a);
	
}
