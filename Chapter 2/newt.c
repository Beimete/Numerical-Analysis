#include "stdio.h"
#include "math.h"
  int newt(x,eps,js,f)
  int js;
  double *x,eps;
  void (*f)();
  { 
    int k,l;
    double y[2],d,p,x0,x1;
    l=js; 
    k=1; 
    x0=*x;
    (*f)(x0,y);
    d=eps+1.0;
    while ((d>=eps)&&(l!=0)){
        if (fabs(y[1])+1.0==1.0){
             printf("err\n"); 
             return(-1);
            }
        x1=x0-y[0]/y[1];
        (*f)(x1,y);
        d=fabs(x1-x0); p=fabs(y[0]);
        if (p>d) d=p;
        x0=x1; l=l-1;
      }
    *x=x1;
    k=js-l;
    return(k);
  }

