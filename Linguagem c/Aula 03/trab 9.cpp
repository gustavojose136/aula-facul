#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
	float n1, n2, n3, n4, a;
	printf("Digite a primeira nota: \n");
	scanf("%f", &n1);
	fflush(stdin);
	printf("Digite a segunda nota: \n");
	scanf("%f", &n2);
	fflush(stdin);
	printf("Digite a terceira nota: \n");
	scanf("%f", &n3);
	fflush(stdin);
	printf("Digite a quarta nota: \n");
	scanf("%f", &n4);
	fflush(stdin);
	a=(n1+n2+n3+n4)/4;
	printf("Sua media e= %.1f", a);

}
