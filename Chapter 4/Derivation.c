#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define PI 3.14159265358979

void main(){
    double X[100],Y[100];
    double X1=0;
    double Y1=0;
    double X2=0;
    double Y2=0;
    double X3=0;
    double Y3=0;
    double X1Y1=0;
    double X1Y2=0;
    double X2Y1=0;
    double eps=0.05;
    for(int i=1; i<101; i++){
        X[i] = 1.0 + pow(-1.0, i)*eps + 3*cos(i*PI/50.0);
        Y[i] = 10.0 + 3 * sin((i/50.0+eps)*PI);
        // printf("The Value of X(%d)=%13.10e\n",i, X[i]);
        // printf("The Value of Y(%d)=%13.10e\n",i, Y[i]);
        X1 = X1 + X[i];
        Y1 = Y1 + Y[i];
        X2 = X2 + X[i]*X[i];
        Y2 = Y2 + Y[i]*Y[i];
        X3 = X3 + X[i]*X[i]*X[i];
        Y3 = Y3 + Y[i]*Y[i]*Y[i];
        X1Y1 = X1Y1 + X[i]*Y[i];
        X1Y2 = X1Y2 + X[i]*Y[i]*Y[i];
        X2Y1 = X2Y1 + X[i]*X[i]*Y[i];
    }
    printf("The Value of X1=%13.10e\n", X1);
    printf("The Value of Y1=%13.10e\n", Y1);
    printf("The Value of X2=%13.10e\n", X2);
    printf("The Value of Y2=%13.10e\n", Y2);
    printf("The Value of X3=%13.10e\n", X3);
    printf("The Value of Y3=%13.10e\n", Y3);
    printf("The Value of X1Y1=%13.10e\n", X1Y1);
    printf("The Value of X1Y2=%13.10e\n", X1Y2);
    printf("The Value of X2Y1=%13.10e\n", X2Y1);
    double A,D,E,G,H;
    double a,b,c,x,y,r;
    double N = 100;
    A = N*X2 - X1*X1;
    D = N*X1Y1 - X1*Y1;
    E = N*X3 + N*X1Y2 - (X2+Y2)*X1;
    G = N*Y2 - Y1*Y1;
    H = N*X2Y1 + N*Y3 - (X2+Y2)*Y1;
    printf("The Value of A = %13.10e\n", A);
    printf("The Value of D = %13.10e\n", D);
    printf("The Value of E = %13.10e\n", E);
    printf("The Value of G = %13.10e\n", G);
    printf("The Value of H = %13.10e\n", H);
    b = (E*G-D*H)/(A*G-D*D);
    c = (A*H-D*E)/(A*G-D*D);
    a = (X2+Y2-b*X1-c*Y1)/N;
    x = b/2.0;
    y = c/2.0;
    r = sqrt(a*4.0 + b*b + c*c)/2.0;
    printf("The Value of a = %13.10e\n", a);
    printf("The Value of b = %13.10e\n", b);
    printf("The Value of c = %13.10e\n", c);
    printf("The Value of x* = %13.10e\n", x);
    printf("The Value of y* = %13.10e\n", y);
    printf("The Value of r = %13.10e\n", r);
}