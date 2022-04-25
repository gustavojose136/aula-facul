#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	int main(void){
		float x,y,z,c,m;
		printf("Digite a idade do primeiro aluno:\n");
		scanf("%f",&x);
		fflush(stdin);
		printf("Digite a idade do segundo aluno:\n");
		scanf("%f",&y);
		fflush(stdin);
		printf("Digite a idade do terceiro aluno:\n");
		scanf("%f",&z);
		fflush(stdin);
		printf("Digite a idade do quarto aluno:\n");
		scanf("%f",&c);
		fflush(stdin);
		m=(x+y+z+c)/4;
		if(m<25){
				printf("Turma Jovem");
			}else if(m<=40){
				printf("Turma Adulta");
			}else if(m>40){
				printf("Turma Idosa");
			}		
		}
