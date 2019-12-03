#include "math.h"
#include "stdio.h"

int newt(x,eps,js,f)
  int js;
  double *x, eps;
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

void main(){
    int js, k;
    double x0, eps;
    void g(double, double []);
    eps = 0.000000005;
    js = 1000;
    x0 = 10.0;
    k = newt(&x0, eps, js, g);
    if(k>=0){
        printf("a=%13.10e\n", x0);
    }

}

void g(a, x)
double a, x[2];
{ 
    x[0] = (2/3.0)*exp(-3*a/2.0)*(a+2/3.0)-0.25*pow(10, -8);
    x[1] = (-1.0*a)*exp(-3*a/2.0);
    return;
}

