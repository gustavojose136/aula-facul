#include <stdio.h>
#include <stdlib.h>
		
	int main (void){
		int qtd_notas, i;
		float soma, media, notas;
		
		printf("Digite a quantidade de notas obtidas no semestre: \n");
		scanf("%i", &qtd_notas);
		fflush(stdin);
		
		for(i = 0; i<qtd_notas; i++){
			printf("Digite a %i nota: ", i+1);
			scanf("%f", &notas);
			fflush(stdin);
			if(notas>=0 && notas<=10){
			soma+=notas;
			}else{
				printf("Erro, nota invalida! \n");
				i--;
			}
		}
		media=soma/qtd_notas;
		printf("A media sera de: %.1f", media);
	}
