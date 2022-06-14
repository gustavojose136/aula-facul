#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	int a[3][3], b[3][3], r[3][3], i, j;
	
	// entrada
	printf("Dados da matriz A:\n\n");
	for(i=0;i<3;i++){ // linha
		for(j=0;j<3;j++){ // coluna
			printf("Digite A[%i][%i]: ",i,j);
			scanf("%i",&a[i][j]);
			fflush(stdin);
		}
	}
	printf("\nDados da matriz B:\n\n");
	for(i=0;i<3;i++){ // linha
		for(j=0;j<3;j++){ // coluna
			printf("Digite B[%i][%i]: ",i,j);
			scanf("%i",&b[i][j]);
			fflush(stdin);
		}
	}
	
	// processamento
	for(i=0;i<3;i++){ // linha
		for(j=0;j<3;j++){ // coluna
			r[i][j]=a[i][j]+b[i][j];
		}
	}
