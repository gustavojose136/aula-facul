#include <stdio.h>
#include <stdlib.h>

int main(void){
	// vari�veis
	float vetor[10];
	int i;
	
	// entrada
	for(i=0;i<10;i++){
		printf("Digite %i numero: ",i+1);
		scanf("%f",&vetor[i]);
		fflush(stdin);
	}
	
	// sa�da
	printf("\nOs numero sao: \n");
	for(i=9;i>=0;i--){
		printf("%f\n",vetor[i]);
	}
	
	return 0;
}
