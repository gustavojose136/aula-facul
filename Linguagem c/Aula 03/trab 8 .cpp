#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
	float n1, n2, a;
	printf("Digite um numero: \n");
	scanf("%f", &n1);
	fflush(stdin);
	printf("Digite outro numero: \n");
	scanf("%f", &n2);
	fflush(stdin);
	a = n1+n2;
	printf("a soma e igual a= %.0f",a);
}
