/*
3.Fazer um programa que possibilite várias opções de cálculos a partir de um menu. 
O programa chamará a função correspondente a cada cálculo.
[ a ] S = 1/1 + 3/2 + 5/3+........+ 99/50
[ b ] S = 1/1 -2/2 + 3/3 -..........-10/10
[ c ] S = 1000/1 -997/2 + 994/3.........
[ d ] S = 480/10 -475/11 + 470/12 -.......
[ f  ] FIM
Obs.: Nas opções [c] e [d] fazer os cálculos para os 20 primeiros termos.
*/
#include <stdio.h>
#include <stdlib.h>

// prototipo das funções:
void fa(void);
void fb(void);
void fc(void);
void fd(void);

int main(void){
	// variáveis
	char opcao;
	
	// entrada
	do{
		system("cls");
		printf("[a] S = 1/1 + 3/2 + 5/3 +........+ 99/50\n");
		printf("[b] S = 1/1 - 2/2 + 3/3 -........- 10/10\n");
		printf("[c] S = 1000/1 -997/2 + 994/3...........\n");
		printf("[d] S = 480/10 -475/11 + 470/12 -.......\n");
		printf("[f] FIM\n");
		printf("Digite uma opcao: ");
		scanf("%c",&opcao);
		fflush(stdin);
		
		// processmento
		switch(opcao){
			case 'a':
				fa();
				break;
			case 'b':
				fb();
				break;
			case 'c':
				fc();
				break;
			case 'd':
				fd();
				break;
			case 'f':
				printf("Saindo...\n");
				break;
			default:
				printf("ERRO! Opcao invalida.\n");
		}
		getch();
	}while(opcao!='f');
	
	return 0;	
}

void fa(void){
	// variáveis locais
	int i, j;
	float s;
	
	// procesamento
	for(i=1,j=1;i<=99,j<=50;i+=2,j++){
		s+=(float)i/j;
	}
	
	// saída
	printf("S = 1/1 + 3/2 + 5/3 +........+ 99/50 = %f\n",s);
}
void fb(void){
	
	// variáveis locais
	int i,j;
	float s;
	
	// processamento
	for(i=1,j=1;i<=10,j<=10;i++,j++){
		if(i%2==0){
			s-=(float)i/j;
		}else{
			s+=(float)i/j;
		}
	}
	
	// saída
	printf("S = 1/1 - 2/2 + 3/3 -........- 10/10 = %f\n",s);
	
}
void fc(void){
	// variáveis locais
	int i, n1=1000, n2=1;
	float s;
	
	// processamento
	for(i=1;i<=20;i++){
		if(n2%2==0){
			s-=(float)n1/n2;
		}else{
			s+=(float)n1/n2;
		}
		n1-=3;
		n2++;
	}
	
	// saída
	printf("S = 1000/1 -997/2 + 994/3........... = %f\n",s);
}
void fd(void){
	// variáveis locais
	int i, n1=480, n2=10;
	float s;
	
	// processamento
	for(i=1;i<=20;i++){
		if(n2%2!=0){
			s-=(float)n1/n2;
		}else{
			s+=(float)n1/n2;
		}
		n1-=5;
		n2++;
	}
	
	// saída
	printf("S = 480/10 -475/11 + 470/12 -....... = %f\n",s);
}

