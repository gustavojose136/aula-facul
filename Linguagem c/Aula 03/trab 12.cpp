#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
	
	int qdt_maquinas;
	printf("quantas maquinas: ");
	scanf("%i", &qdt_maquinas);
	fflush(stdin);
	printf("modelo      quantidade\n");
	printf("20cv 		%ipc \n",1*qdt_maquinas);
	printf("1cv 		%ipc \n",2*qdt_maquinas);
	printf("5cv 		%ipc \n",3*qdt_maquinas);
	printf("Custo total..........R$ %i,00\n", (1*1500)+(2*300)+(3*600));
	printf("Custo Tipo Motor.....\n");
	printf("20cv................. R$ %i,00\n", 1500);
	printf("5cv.................. R$ %i,00\n", 600);
	printf("1cv.................. R$ %i,00\n", 300);	
	printf("\nCusto Total Compra R$ %i,00\n",(1*1500)+(2*300)+(3*600)*qdt_maquinas );
	
	
	
	return 0;	
}
