#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double Hilb(double *h, int n)
{
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  {
    h[j+n*i]=1/((i+j+1)*1.0);
  }
  return *h;
}

double InfinNorm_Hilb(double *h, int n)
{
    double norm, nor=0.0;
    for(int i=0; i<n; i++){
        norm = 0.0;
        for(int j=0; j<n; j++){
            norm = norm + fabs(h[i*n+j]);
        }
        if(nor<=norm)
        nor = norm;
    }
    return nor;
}

void main(){
    double hilb[100000];
    Hilb(hilb, 4);
    printf("Infinite Norm IS:%13.2e\n", InfinNorm_Hilb(hilb, 4));
}

