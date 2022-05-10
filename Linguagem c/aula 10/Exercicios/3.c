#include <stdio.h>
#include <stdlib.h>
		
	int main (void){
		int i, num, maior, menor;
		for(i = 0; i < 10; i++){
			printf("Digite o %i numero:  ", i+1);
			scanf("%i", &num);
			fflush(stdin);
			
			if(i==0){
				menor=num;
				maior=num;
			}if (num>maior){
				maior=num;
			}else if(num<menor){
				menor=num;
			}
		}
		printf("A diferenca entre o maior e o menor numero vai ser de= %i-%i=%i", maior, menor, maior-menor);
	}
