#include <stdio.h>
#include <stdlib.h>
#include <math.h>
		int main() {
    		char letra;

    		printf("Digite um caracter: ");
    		scanf("%c", &letra);
    	
    	if(letra>='a' && letra<='z'){
				letra=letra+'a'-'A';
		}
    	if(letra == 'a' || letra == 'A' || letra == 'e' || letra == 'E' || letra == 'i'
       	|| letra == 'I' || letra == '0' || letra == 'O' || letra == 'u' || letra == 'U'){
        	printf("Vogal\n");
   		  }else{			 
        	printf("Consoante\n");
		}
		}else{			
			printf("Nao e uma letra");}
				
		}
