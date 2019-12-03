#include "math.h"
#include "stdio.h"
#include "newt.c"

void main(){
    int js, k;
    double x1, x2, eps;
    void newtf(double, double []);
    eps = 0.00000005;
    js = 1000;
    x1 = log(5);
    k = newt(&x1, eps, js, newtf);
    if(k>=0){
        printf("k=%d    x1=%13.7e\n", k, x1);
    }

    x2 = log(10);
    k = newt(&x2, eps, js, newtf);
    if(k>=0){
        printf("k=%d    x2=%13.7e\n", k, x2);
    }
    printf("\n");
}

void newtf(x, y)
double x, y[2];
{
    y[0] = 6.0*x-exp(x);
    y[1] = 6.0-exp(x);
    return;
}