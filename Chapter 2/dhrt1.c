#include "math.h"
#include "stdio.h"
#include "dhrt.c"
void main(){
    int i, n;
    static int m = 5;
    static double x[5];
    double f(double);
    n = dhrt(-10.0, 10.0, 0.2, 0.00000005, x, m, f);
    printf("M=%d\n", n);
    for(i=0; i<=n-1; i++){
        printf("x(%d)=%13.7e\n", i, x[i]);
    }
    printf("\n");
}

double f(x)
double x;
{
    double z;
    z = 3.0*x*x-exp(x);
    return(z);
}