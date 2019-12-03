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
    double h,t1,t2,s1,s2,ep,p,x;
    n=2;h=(b-a)/n;
    t1=h*((*f)(a)+2*(*f)(a+h)+(*f)(b))/2.0;
    s1=t1;
    ep=eps+1.0;
    while (ep>=eps)
      { p=0.0;
        for (k=0;k<=n-1;k++)
          { x=a+(k+0.5)*h;
            p=p+(*f)(x);
          }
        t2=(t1+h*p)/2.0;
        s2=(4.0*t2-t1)/3.0;
        ep=fabs(s2-s1);
        t1=t2; s1=s2; n=n+n; h=h/2.0;
      }

    printf("The Value of n = %d\n", n);
    printf("The Value of h = %13.10e\n", 1.0/n);
    printf("t=%13.10e\n", s2);
    printf("ABS of |(-4/9)-S|=%13.10e\n", fabs((-4/9.0)-s2));
}