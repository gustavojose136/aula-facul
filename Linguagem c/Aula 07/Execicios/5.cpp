#include <stdio.h>
#include <math.h>

	int main(void){
		float x;
		int aux;
		printf("Digite algum numero: \n");
		scanf("%f",&x);
		fflush(stdin);
		aux=x;
		if(x==aux){
			printf("O numero e inteiro");
		}else{
   			printf("O numero e real");
		}
	}
