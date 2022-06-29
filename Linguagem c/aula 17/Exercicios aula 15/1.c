#include <stdio.h>
#include <stdlib.h>
//""
	int testeNumero(int numero);
	

	int main(void){
		int n;
	
		printf("Digite um numero: ");
		scanf("%i", &n);
		
		if(testeNumero(n)){
			printf("O numero e impar \n");
		}else{
			printf("O numero e par \n");
		}	
		return 0;
	}
	
	
	int testeNumero(int numero){
		if(numero%2==0){
			return 0;
		}else{
			return 1;
		}
	}
