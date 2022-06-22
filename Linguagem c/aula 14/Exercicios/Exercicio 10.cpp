#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main(void){
	// variáveis
	int a[TAM][TAM], i, j, k;
	
	// entrada
	printf("Dados da matriz:\n\n");
	for(i=0;i<TAM;i++){ // linha
		for(j=0;j<TAM;j++){ // coluna
			printf("Digite [%i][%i]: ",i,j);
			scanf("%i",&a[i][j]);
			fflush(stdin);
		}
	}
	printf("Digite o valor de K: ");
	scanf("%i",&k);
	fflush(stdin);
	
	// processamento
	for(i=0;i<TAM;i++){
		a[i][i]=a[i][i]*k;
	}
	
	// Saída
	printf("\nA matriz:\n\n");
	for(i=0;i<TAM;i++){ // linha
		for(j=0;j<TAM;j++){ // coluna
			printf("%i\t",a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

