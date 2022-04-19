#include <stdlib.h>
#include <stdio.h>
#include <math.h>

	int main(void){
		char t;
		printf("Qual o seu turno na faculdade?(Utilize m-matutino ou v-vespertino ou n-noturno)\n");
		scanf("%c", &t);
		fflush(stdin);
		if(t=='m'){
			printf("Bom dia, voce estuda de manha!");
		}else if(t=='v'){
			printf("Boa tarde, voce estuda de tarde");
		}else if(t=='n'){
			printf("Boa noite, voce estuda de noite");
		}else{
			printf("Comando invalido, tente novamente");
		}
		return 0;
	}
