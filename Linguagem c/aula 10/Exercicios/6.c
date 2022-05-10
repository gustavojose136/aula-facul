#include <stdio.h>
#include <stdlib.h>
		
	int main (void){
		int qtd_notas, i;
		float soma, media, notas;
		
		printf("Digite a quantidade de CD's': \n");
		scanf("%i", &qtd_notas);
		fflush(stdin);
		
		for(i = 0; i<qtd_notas; i++){
			printf("Digite o valor do %i CD: ", i+1);
			scanf("%f", &notas);
			fflush(stdin);
			soma+=notas;
		}
		media=soma/qtd_notas;
		printf("A media de alunos por turma sera de: %.1f", media);
	}
