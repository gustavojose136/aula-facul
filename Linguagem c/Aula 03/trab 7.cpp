#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	float cm,m;
	printf("Digite os metros: \n");
	scanf("%f", &m);
	fflush(stdin);
	cm = m *100;
	printf("Seus centimetros sao: %.0f cm", cm);
	return 0;
	
}
