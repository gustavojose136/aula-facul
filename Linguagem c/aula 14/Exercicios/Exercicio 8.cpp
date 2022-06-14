/*
8. Construa um algoritmo que leia uma matriz quadrada de ordem 3. Leia uma 
constante K, diminui a diagonal principal por esta constante e imprima a matriz 
diminuida.
R.:
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int main(void){
	// variáveis
	int a[TAM][TAM], r[TAM][TAM], i, j, k;
	
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
	/*
	for(i=0;i<TAM;i++){ // linha
		for(j=0;j<TAM;j++){ // coluna
			if(i==j){
				r[i][j]=a[i][j]-k;
			}
		}
	}
	*/
	for(i=0;i<TAM;i++){
		r[i][i]=a[i][i]-k;
	}
	
	// Saída
	printf("\nA matriz:\n\n");
	for(i=0;i<TAM;i++){ // linha
		for(j=0;j<TAM;j++){ // coluna
			printf("%i\t",r[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

