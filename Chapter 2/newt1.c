#include "math.h"
#include "stdio.h"
#include "newt.c"

int main(){
    int js, k;
    double x, eps;
    void newtf(double, double []);
    eps = 0.00000005;
    js = 1000;
    x = 0.29488; // 0.29485, 0.29486, 0.29487
    k = newt(&x, eps, js, newtf);
    if(k>=0){
        printf("k=%d    x=%13.7e\n", k, x);
    }
    printf("\n");
}

void newtf(x, y)
double x, y[2];
{
    y[0] = 3.0*x*x-exp(x);
    y[1] = 6.0*x-exp(x);
    return;
}