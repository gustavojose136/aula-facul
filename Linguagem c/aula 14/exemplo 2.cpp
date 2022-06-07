#include <stdio.h>
#include <stdlib.h>

	int main (void){
		//float n1, n2, n3, n4, n5, media;
		float n[5], media;
		n[0]=3; //n0= 3;
		n[1]=6; //n1=6;
		n[2]=5; //n2=5;
		n[3]=9; //n3=9;
		n[4]=10; //n1=10;
		//media = (n0+n1+n2+n3+n4)/5;
		media= (n[0]+n[1]+n[2]+n[3]+n[4])/5;
		
		printf("n1= %f\n", n[0]);
		printf("n2= %f\n", n[1]);
		printf("n3= %f\n", n[2]);
		printf("n4= %f\n", n[3]);
		printf("n5= %f\n", n[4]);
		printf("A media sera: %f", media);
		
		return 0;
	}
