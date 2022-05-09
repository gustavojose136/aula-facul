#include <stdio.h>
#include <stdlib.h>
		
	int main (void){
		int n1,n2,i;
		printf("Digite um numero\n");
		scanf("%i", &n1);
		fflush(stdin);
		printf("Digite outro numero\n");
		scanf("%i", &n2);
		fflush(stdin);
		for(i=n1;i<n2;i++)
		{if(i% 2 == 0)
	    	printf("%i Numeros\n", i);
		}
		if(n1<n2){}
			for(i=n1;i>=n2;i--){
			if(i% 2 == 0)
			printf("%i Numeros\n", i);
			}
		}
	
					
	
