#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
	int n1, n2;
	float n3, a, b, c, d;
	printf("Digite um numero inteiro: \n");
	scanf("%i",&n1);
	fflush(stdin);
	printf("Digite outro numero inteiro: \n");
	scanf("%i",&n2);
	fflush(stdin);
	printf("Digite um numero real: \n");
	scanf("%f",&n3);
	fflush(stdin);
	a=(n1*2);
	b=(n2/2);
	c=(3*n1)+n3;
	d=(pow(n3,3));
	printf("O dobro do primeiro e: %.1f, e a metade do segundo e: %.1f \n", a, b);
	printf("a soma do triplo do primeiro com o terceiro: %.1f \n", c);
	printf("terceiro elevado ao cubo e: %.1f", d);
	
	
	
}
