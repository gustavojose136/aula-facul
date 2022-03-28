#include <stdio.h> 
#include <math.h> 

int main(void)
{
    float c, f;
    printf("F = "); scanf("%f", &f);
    c = (f - 32) * 5 / 9;
    printf("C = %f", c);
    return(0);
}
