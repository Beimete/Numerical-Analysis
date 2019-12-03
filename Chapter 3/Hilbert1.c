#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "trmul.c"

double Hilb(double *h, int n){
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  {
    h[j+n*i]=1/((i+j+1)*1.0);
  }
  return *h;
}

double InfinNorm_Hilb(double *h, int n){
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

int ssgj(double a[], int n){
   /**
   * 求n阶对称正定矩阵A的逆矩阵A-1(也是一个对称正定矩阵)
   * double a[n][n]
   * int n 矩阵阶数
   * int ssgj() 函数返回标志值，若返回标志值小于0，则表示程序工作失败；
   *              若返回标志值大于0，则表示正常返回
   * */   
  int i,j,k,m;
  double w,g,*b;
  b=malloc(n*sizeof(double));
  for (k=0; k<=n-1; k++)
    { w=a[0];
      if (fabs(w)+1.0==1.0)
        { free(b); printf("fail\n"); return(-2);}
      m=n-k-1;
      for (i=1; i<=n-1; i++)
        { g=a[i*n]; b[i]=g/w;
          if (i<=m) b[i]=-b[i];
          for (j=1; j<=i; j++)
            a[(i-1)*n+j-1]=a[i*n+j]+g*b[j];
        }
      a[n*n-1]=1.0/w;
      for (i=1; i<=n-1; i++)
        a[(n-1)*n+i-1]=b[i];
    }
  for (i=0; i<=n-2; i++)
  for (j=i+1; j<=n-1; j++)
    a[i*n+j]=a[j*n+i];
  free(b);
  return(2);
}

double InfinCond_Hilb(double *h, int n){
    double cond, h_[100000];
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        h_[i*n+j] =h[i*n+j];
    ssgj(h, n);
    cond = InfinNorm_Hilb(h_, n)*InfinNorm_Hilb(h, n);
    return cond;
}

void main(){
    // int i, j;
    // double hilb[100000], hilb_[10000], c[4][4];
    // Hilb(hilb, 4);
    // for(i=0; i<=3; i++)
    // for(j=0; j<=3; j++)
    //     hilb_[i*4+j] = hilb[i*4+j];
    // i = ssgj(hilb, 4);
    // if(i>0){
    //      printf("MAT hilb IS:\n");
    //     for(i=0; i<=3; i++){
    //         for(j=0; j<=3; j++)
    //             printf("%13.6e  ", hilb_[i*4+j]);
    //         printf("\n");
    //     }
    //     printf("\n");
    //     printf("MAT hilb- IS:\n");
    //     for(i=0; i<=3; i++){
    //         for(j=0; j<=3; j++)
    //             printf("%13.6e  ", hilb[i*4+j]);
    //         printf("\n");
    //     }
    //     printf("\n");
    //     printf("MAT hilb*hilb- IS:\n");
    //     trmul(hilb_, hilb, 4, 4, 4, c);
    //     for(i=0; i<=3; i++){
    //         for(j=0; j<=3; j++)
    //             printf("%13.6e  ", c[i][j]);
    //         printf("\n");
    //     }
    //     printf("\n");
    // }

    // Hilb(hilb, 5);
    // printf("n= 5 Infinite Cond IS:  %13.6e\n",InfinCond_Hilb(hilb, 5));
    // printf("\n");


    // Hilb(hilb, 100);
    // printf("n=100 Infinite hilb Norm IS:  %13.6e\n",InfinNorm_Hilb(hilb, 100));
    // ssgj(hilb, 100);
    // printf("n=100 Infinite hilb_ Norm IS:  %13.6e\n",InfinNorm_Hilb(hilb, 100));

    // Hilb(hilb, 100);
    // printf("n=100 Infinite Cond IS:  %13.6e\n",InfinCond_Hilb(hilb, 100));
    
    for(int k=10; k<101; k+=10){
      double hilb[100000];
      Hilb(hilb, k);
      printf("n=%d Infinite Cond IS:  %13.6e\n",k,log(InfinCond_Hilb(hilb, k)));
    }

}