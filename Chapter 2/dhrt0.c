#include "math.h"
#include "stdio.h"
#include "dhrt.c"
int main(){
    int i, n;
    static int m = 5;
    static double x[5];
    double dhrtf(double);
    n = dhrt(0.0, 3.0, 0.2, 0.00000005, x, m, dhrtf);
    printf("M=%d\n", n);
    for(i=0; i<=n-1; i++){
        printf("x(%d)=%13.7e\n", i, x[i]);
    }
    printf("\n");
}

double dhrtf(x)
double x;
{
    double z;
    z = 6.0*x-exp(x);
    return(z);
}