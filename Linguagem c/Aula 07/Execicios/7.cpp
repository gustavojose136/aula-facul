#include <stdio.h>
#include <stdlib.h>
#include <math.h>
		int main() {
    		char letra;

    		printf("Digite um caracter: ");
    		scanf("%c", &letra);
    	if(letra == 'a' || letra == 'A' || letra == 'e' || letra == 'E' || letra == 'i'
       	|| letra == 'I' || letra == '0' || letra == 'O' || letra == 'u' || letra == 'U')
        	printf("\tVogal...\n");
   		 else
        	printf("\tConsoante\n");
}
