#include <stdio.h>
#include <stdlib.h>

int main(void){
	// vari�veis
	char vetor[50][15];
	int i;
	
	// entrada
	for(i=0;i<15;i++){
		printf("Digite %i palavra: ",i+1);
		gets(vetor[i]);
		fflush(stdin);
	}
	
	// sa�da
	printf("\nOs numero sao: \n");
	for(i=14;i>=0;i--){
		printf("%s\n",vetor[i]);
	}
	
	return 0;
}
