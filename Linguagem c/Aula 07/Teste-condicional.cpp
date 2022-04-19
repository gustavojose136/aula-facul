#include <stdio.h>
#include <stdlib.h>

int main (void){
	int n1, n2;
	
	printf("Digite n1: \n");
	scanf("%i", &n1);
	fflush(stdin);
	printf("Digite n2: \n");
	scanf("%i", &n2);
	fflush(stdin);
	if (n1>n2){
		printf("%i",n1);
	}else {
	if (n1<n2){
		printf("%i",n2);
	}else{
		printf("iguais");
	}
	}
	return 0;
	}

