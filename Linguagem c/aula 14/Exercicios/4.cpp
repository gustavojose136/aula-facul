#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	int i, cont=0;
	char v[10], l;
	
	// entrada
	for(i=0;i<10;i++){
		printf("Digite %i caracter: ", i+1);
		scanf("%c",&l);
		if((l>='a' && l<='z' )|| (l>='A' &&l<='Z')) {
			v[i]=l;
		}else{
			printf("Erro, valor invalido!\n");
			i--;
		}
		fflush(stdin);
	}
	
	// processamento
	for(i=0;i<10;i++){
		if(v[i]!='a' && v[i]!='e' && v[i]!='i' && v[i]!='o' && v[i]!='u'
			&&
		   v[i]!='A' && v[i]!='E' && v[i]!='I' && v[i]!='O' && v[i]!='U'){
			cont++;
		}
	}
	
	// saída
	printf("A quantidade de consoantes: %i\n", cont);
	printf("As consoantes sao: ");
	for(i=0;i<10;i++){
		if(v[i]!='a' && v[i]!='e' && v[i]!='i' && v[i]!='o' && v[i]!='u'
			&&
		   v[i]!='A' && v[i]!='E' && v[i]!='I' && v[i]!='O' && v[i]!='U'){
			printf("%c, ",v[i]);
		}
	}
	return 0;
}
