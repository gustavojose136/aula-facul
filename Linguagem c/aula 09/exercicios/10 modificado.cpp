#include <stdlib.h>
#include <stdio.h>
#include <math.h>

	int main(void){
		int c, n1, n2;
		printf("Escolha umas das opcoes:\n[ 1 ] Adicao\n[ 2 ] Subtracao\n[ 3 ] Multiplicacao\n[ 4 ] Divisao\n[ 5 ] Fim\n");
		scanf("%i", &c);
		fflush(stdin);
		do{
		system("cls");
		switch(c){
		case 1:
			printf("Digite um numero\n");
			scanf("%i", &n1);
			fflush(stdin);
			printf("Digite outro numero\n");
			scanf("%i", &n2);
			fflush(stdin);
			printf("A soma da conta ira ser %i",n1+n2);
			break;
		case 2:
			printf("Digite um numero\n");
			scanf("%i", &n1);
			fflush(stdin);
			printf("Digite outro numero\n");
			scanf("%i", &n2);
			fflush(stdin);
			printf("A subtracao da conta ira ser %i",n1-n2);
			break;
		case 3:
			printf("Digite um numero\n");
			scanf("%i", &n1);
			fflush(stdin);
			printf("Digite outro numero\n");
			scanf("%i", &n2);
			fflush(stdin);
			printf("A multiplicacao da conta ira ser %i",n1*n2);
			break;
		case 4:
			printf("Digite um numero\n");
			scanf("%i", &n1);
			fflush(stdin);
			printf("Digite outro numero\n");
			scanf("%i", &n2);
			fflush(stdin);
			if(n2>0){
			printf("A divisao da conta ira ser %i",n1/n2);}
			else{
				printf("ERRO! Divisao por zero");
			}
		}	getch();	
		}while(c!=5);
		
	}
