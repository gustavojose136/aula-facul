#include <stdio.h>
#include <stdlib.h>
//""
	
	void imprime(char caracter, int linha);
	int main (void){
		char letra;
		int quantidade;
		
		printf("Digite o caracter: ");
		scanf("%c", &letra);
		fflush(stdin);
		printf("Digite a quantidade: ");
		scanf("%i", &quantidade);
		
		
		return 0;
	}
	
	void imprime(char caracter, int linha){
		int l,c;
		for(l=1;l<=linha; l++){
			for(c=1;c<=79;c++){
				printf("%c", caracter);
			}
		printf("\n");
	}
	}
