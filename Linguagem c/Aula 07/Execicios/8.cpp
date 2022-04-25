#include <stdio.h>
#include <stdlib.h>
#include <math.h>

		int main(void){
			int x, y, z, aux;
			printf("Digite um numero\n");
			scanf("%i",&x);
			fflush(stdin);
			printf("Digite outro numero\n");
			scanf("%i",&y);
			fflush(stdin);
			printf("Digite outro numero\n");
			scanf("%i",&z);
			fflush(stdin);
			if(x>y){
				aux=x;x=y;y=aux;
			}if(x>z){
				aux=x;x=z;z=aux;
			}if(y>z){
				aux=y;y=z;z=aux;
			}
			printf("A ordem crescente e: %i, %i e %i",x,y,z);
		}
