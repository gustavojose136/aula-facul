#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	int a[5][5], b[5][5], r[5][5], i, j;
	
	// entrada
	printf("Dados da matriz A:\n\n");
	for(i=0;i<5;i++){ // linha
		for(j=0;j<5;j++){ // coluna
			printf("Digite A[%i][%i]: ",i,j);
			scanf("%i",&a[i][j]);
			fflush(stdin);
		}
	}
	printf("\nDados da matriz B:\n\n");
	for(i=0;i<5;i++){ // linha
		for(j=0;j<5;j++){ // coluna
			printf("Digite B[%i][%i]: ",i,j);
			scanf("%i",&b[i][j]);
			fflush(stdin);
		}
	}
	
	// processamento
	for(i=0;i<5;i++){ // linha
		for(j=0;j<5;j++){ // coluna
			r[i][j]=a[i][j]-b[i][j];
		}
	}
	
	// Saída
	printf("\nA matriz R:\n\n");
	for(i=0;i<5;i++){ // linha
		for(j=0;j<5;j++){ // coluna
			printf("%i\t",r[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

