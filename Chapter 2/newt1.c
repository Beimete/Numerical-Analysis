#include "math.h"
#include "stdio.h"
#include "newt.c"

void main(){
    int js, k;
    double x3, x4, x5, eps;
    void newtf(double, double []);
    eps = 0.00000005;
    js = 1000;
    x3 = -0.835; 
    k = newt(&x3, eps, js, newtf);
    if(k>=0){
        printf("k=%d    x3=%13.7e\n", k, x3);
    }

    x4 = 0.953; 
    k = newt(&x4, eps, js, newtf);
    if(k>=0){
        printf("k=%d    x4=%13.7e\n", k, x4);
    }

    x5 = 3.657; 
    k = newt(&x5, eps, js, newtf);
    if(k>=0){
        printf("k=%d    x5=%13.7e\n", k, x5);
    }
}

void newtf(x, y)
double x, y[2];
{
    y[0] = 3.0*x*x-exp(x);
    y[1] = 6.0*x-exp(x);
    return;
}