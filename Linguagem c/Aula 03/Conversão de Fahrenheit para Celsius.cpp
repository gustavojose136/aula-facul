#include <stdio.h> 
#include <math.h> 

int main(void)
{
    float c, f;
    printf("F = "); 
	scanf("%f", &f);
	fflush(stdin);
    c = (f - 32) * 5 / 9;
    printf("C = %1.f", c);
    return(0);
}
