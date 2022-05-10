#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	float p_a = 80000, p_b = 200000, t_a=0.03, t_b = 0.015;
	int anos = 0;
	
	while(p_a <= p_b){
		p_a+=(p_a*t_a);
		p_b+=(p_b*t_b);
		anos++;
	}
	
	printf("A quantidade de anos e %i\n", anos);
	return(0);
}
