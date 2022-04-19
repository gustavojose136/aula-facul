#include <stdio.h>
#include <math.h>

	int main(void){
		int x;
		printf("Digite algum numero: \n");
		scanf("%d",&x);
		fflush(stdin);
		if(x % 2){
			printf("seu numero e par so pra trocar");
		}else{
   			printf("seu numero e impar so pra trocar");
		}
	}
