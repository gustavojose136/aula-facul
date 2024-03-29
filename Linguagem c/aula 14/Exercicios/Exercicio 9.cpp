/*
9. Construa um algoritmo que leia uma matriz quadrada de ordem 4. Leia uma 
constante K, multiplique a diagonal principal por esta constante e imprima a matriz 
multiplicada.
R.:
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 4

int main(void){
	// vari�veis
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
	
	// Sa�da
	printf("\nA matriz:\n\n");
	for(i=0;i<TAM;i++){ // linha
		for(j=0;j<TAM;j++){ // coluna
			printf("%i\t",a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

