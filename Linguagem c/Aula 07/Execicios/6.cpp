#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	int main(void){
		char s;
		printf("Digite seu sexo(use apenas f/m) \n");
		scanf("%c", &s);
		if (s=='f'){
			printf("Seu sexo e feminino");
		}else if(s=='m'){
			printf("Seu sexo e masculino");
		}else{
			printf("Sexo invalido, escreva apenas f/m");
		}
	}
