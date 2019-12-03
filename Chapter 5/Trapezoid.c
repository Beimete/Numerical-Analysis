#include "math.h"
#include "stdio.h"

double f(x)
double x;
{ 
    double y;
    y=sqrt(x)*log(x+0.00000000000001);
    return(y);
}

void main(){
    double a,b,eps;
    a=0.0; b=1.0; eps=0.00000000001;
    int n,k;
    double fa,fb,h,t1,p,s,x,t,fm;
    fa=(*f)(a); fb=(*f)(b);
    n=2;h=(b-a)/n;
    fm=(*f)(a+h);
    t1=h*(fa+2*fm+fb)/2.0;
    p=eps+1.0;
    while (p>=eps)
    { 
        s=0.0;
        for (k=0;k<=n-1;k++){ 
            x=a+(k+0.5)*h;
            s=s+(*f)(x);
        }
        t=(t1+h*s)/2.0;
        p=fabs(t1-t);
        t1=t; n=n+n; h=h/2.0;
    }
    printf("The Value of n = %d\n", n);
    printf("The Value of h = %13.10e\n", 1.0/n);
    printf("t=%13.10e\n",t);
    printf("ABS of |(-4/9)-t|=%13.10e\n", fabs((-4/9.0)-t));
}