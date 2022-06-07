#include <stdio.h>
#include <stdlib.h>

#define tam 10

	int main (void){
		int n[tam], soma;
		n[0]=1;
		n[1]=2;
		n[2]=3;
		n[3]=4;
		n[4]=5;
		n[6]=6;
		n[7]=8;
		n[8]=9;
		n[9]=10;
		
		soma=n[0]+n[1]+n[2]+n[3]+n[4]+n[5]+n[6]+n[7]+n[8]+n[9];
		
		printf("a soma sera de: %i", soma);
		
		
		return 0;
	}
