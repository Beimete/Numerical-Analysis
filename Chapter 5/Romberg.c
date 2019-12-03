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
    a=0.0; b=1.0; eps=0.0000000000000001;
    int m,n,i,k;
    double y[10],h,ep,p,x,s,q;
    n=2; h=(b-a)/n;
    y[0]=h*((*f)(a)+2*(*f)(a+h)+(*f)(b))/2.0;
    m=1; ep=eps+1.0;
    while ((ep>=eps)&&(m<=9))
      { p=0.0;
        for (i=0;i<=n-1;i++)
          { x=a+(i+0.5)*h;
            p=p+(*f)(x);
          }
        p=(y[0]+h*p)/2.0;
        s=1.0;
        for (k=1;k<=m;k++)
          { s=4.0*s;
            q=(s*p-y[k-1])/(s-1.0);
            y[k-1]=p; p=q;
          }
        ep=fabs(q-y[m-1]);
        m=m+1; y[m-1]=q; n=n+n; h=h/2.0;
      }

    printf("The Value of n = %d\n", n);
    printf("The Value of h = %13.10e\n", 1.0/n);
    printf("t=%13.10e\n", q);
    printf("ABS of |(-4/9)-R|=%13.10e\n", fabs((-4/9.0)-q));
}