#include "math.h"
#include "stdio.h"

void main(){
    double a, b, eps, f(double);
    a=0.0; b=14.758333; eps=0.00000005;

    int m,n,i,k;
    double y[10],h,ep,p,x,s,q;
    n=1; h=b-a;
    y[0]=h*((*f)(a)+(*f)(b))/2.0;
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
        { 
            s=4.0*s;
            q=(s*p-y[k-1])/(s-1.0);
            y[k-1]=p; p=q;
        }
        ep=fabs(q-y[m-1]);
        m=m+1; y[m-1]=q; n=n+n; h=h/2.0;
    }

    printf("The Number of Key Points = %d\n", n+1);
    printf("K=%13.12e\n", q);
    printf("ABS of |(-4/9)-R2n|=%13.10e\n", fabs((-4/9.0)-q));
}

double f(double a){
    double y;
    y = (-1.0*a)*exp(-3*a/2.0);
    return(y);
}
