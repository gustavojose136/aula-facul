#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
	float a, b, c, d, n1;
	d=25;
	printf("Digite quantas horas voce trabalhou este mes: \n");
	scanf("%f", &n1);
	fflush(stdin);
	a= d*n1;
	b= a /100*8;
	c= a-b; 
	printf("%.1f", c);


}
