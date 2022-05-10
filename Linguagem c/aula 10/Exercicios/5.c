#include <stdio.h>
#include <stdlib.h>
		
	int main (void){
		int qtd_notas, i;
		float soma, media, notas;
		
		printf("Digite a quantidade de turmas: \n");
		scanf("%i", &qtd_notas);
		fflush(stdin);
		
		for(i = 0; i<qtd_notas; i++){
			printf("Digite a quantidade de alunos da %i turma: ", i+1);
			scanf("%f", &notas);
			fflush(stdin);
			if(notas>=0 && notas<=40){
			soma+=notas;
			}else{
				printf("Erro, turma invalida!, o numero ultrapassou 40 pessoas \n");
				i--;
			}
		}
		media=soma/qtd_notas;
		printf("A media de alunos por turma sera de: %.1f", media);
	}
