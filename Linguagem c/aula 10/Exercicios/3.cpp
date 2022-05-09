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
		printf("O maior numero vai ser: %i, e o menor:%i", maior, menor);
	}
