#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	int main(void){
		float d;
		printf("Digite um numero que corresponda a um dia da semana(ex: 1-Domingo, 2-Segunda, etc.)\n");
		scanf("%f",&d);
		fflush(stdin);
		if(d==1){
			printf("hoje e domingo");
		}else if(d==2){
			printf("hoje e segunda");
		}else if(d==3){
			printf("hoje e terca");
		}else if(d==4){
			printf("hoje e quarta");
		}else if(d==5){
			printf("hoje e quinta");
		}else if(d==6){
			printf("hoje e sexta");
		}else if(d==7){
			printf("hoje e sabado");
		}else{
			printf("Valor invalido");
		}
			
	}
