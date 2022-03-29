#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
	float m, c;
	printf("Digite o metro: \n");
	scanf("%f", &m);
	c = m*100;
	printf("O metro foi convetido para:%.0f centimetros", c);	
}
