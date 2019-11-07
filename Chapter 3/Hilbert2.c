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

void gsdl(double a[], double b[], int n, double x[], double eps){
 /**
 * 求解对称正定方程组的共轭梯度法 AX=B
 * double a[n][n] 存放对称正定矩阵A
 * int n 方程组的阶数
 * double b[n] 存放方程组右端的常数向量
 * double eps 控制精度要求
 * double x[n] 返回方程组的解向量
 * int gsdl() 函数返回值。若返回的标志值小于0，
 *            则表示系数矩阵不具有主对角占优的绝对优势；
 *              若返回的标志值大于0，则比奥斯古正常返回
 * */
  int i,j;
  double p,t,s,q;
 
  p=eps+1.0;
  while (p>=eps)
    { p=0.0;
      for (i=0; i<=n-1; i++)
        { t=x[i]; s=0.0;
          for (j=0; j<=n-1; j++)
            if (j!=i) s=s+a[i*n+j]*x[j];
          x[i]=(b[i]-s)/a[i*n+i];
          q=fabs(x[i]-t)/(1.0+fabs(x[i]));
          if (q>p) p=q;
        }
    }
  return;
}

void SolveVector_10(double *h, double *s){
  int p, q, k;
  double x[10], S[10], H[10][10], eps = 0.000001;

  for(p=0; p<10; p++)
  for(q=0; q<10; q++)
    H[p][q] = h[p*10+q];

  for(k=0; k<10; k++)
    x[k] = 1.0;

  trmul(H, x, 10, 10, 1, S);
  gsdl(h, S, 10, s, eps);

  for(int j=0; j<10; j++)
    printf("x(%d)=%13.10e\n", j, s[j]);
  return;
}

void SolveVector_50(double *h, double *s){
  int p, q, k;
  double x[50], S[50], H[50][50], eps = 0.000001;
  for(p=0; p<50; p++)
  for(q=0; q<50; q++)
    H[p][q] = h[p*50+q];

  for(k=0; k<50; k++)
    x[k] = 1.0;

  trmul(H, x, 50, 50, 1, S);
  gsdl(h, S, 50, s, eps);

  for(int j=0; j<50; j++)
      printf("x(%d)=%13.10e\n", j, s[j]);
  return;
}

void SolveVector_100(double *h, double *s){
  int p, q, k;
  double x[100], S[100], H[100][100], eps=0.000001;
  for(p=0; p<100; p++)
  for(q=0; q<100; q++)
    H[p][q] = h[p*100+q];

  for(k=0; k<100; k++)
    x[k] = 1.0;

  trmul(H, x, 100, 100, 1, S);
  gsdl(h, S, 100, s, eps);

  for(int j=0; j<100; j++)
      printf("x(%d)=%13.10e\n", j, s[j]);
  return;
}

void main(){
  double norm;

  double nor=0.0, Nor=0.0, X[10], Y[10], A[100], S[10], H[10][10];
  Hilb(A, 10);
  SolveVector_10(A, S);

  for(int c=0; c<10; c++){
    norm = 0.0;
    X[c] = 1.0-S[c];
    // printf("det x(%d)=%13.10e\n", c, X[c]);
    norm = fabs(X[c]);
    printf("ABS of det x(%d)=%13.10e\n", c, norm);
    if(nor <= norm)
      nor = norm;
  }
  printf("the norm of x-x' is: %13.10e\n", nor);

  double x[10], b[10], b_[10];
  for(int k=0; k<10; k++)
    x[k] = 1.0;
  Hilb(A, 10);
  for(int p=0; p<10; p++)
  for(int q=0; q<10; q++)
    H[p][q] = A[p*10+q];
  trmul(H, x, 10, 10, 1, b);
  trmul(H, S, 10, 10, 1, b_);

  for(int e=0; e<10; e++){
    norm = 0.0;
    Y[e] = b[e]-b_[e];
    // printf("det Y(%d)=%13.10e\n", e, Y[e]);
    norm = fabs(Y[e]);
    printf("ABS of det Y(%d)=%13.10e\n", e, norm);
    if(Nor <= norm)
      Nor = norm;
  }
  printf("the norm of b-b_' is: %13.10e\n", Nor);
  printf("\n");
  /**
   *  x(0)=1.0004187379e+000
      x(1)=9.9243525638e-001
      x(2)=1.0285568150e+000
      x(3)=9.7629422157e-001
      x(4)=9.8142305108e-001
      x(5)=1.0030900315e+000
      x(6)=1.0174256368e+000
      x(7)=1.0174590720e+000
      x(8)=1.0036653858e+000
      x(9)=9.7892521428e-001
      the norm of x-x' is: 2.8556815009e-002 
      the norm of b-b_' is: 2.7123996782e-007
  */
  double nor2=0.0, Nor2=0.0, X2[50], Y2[50], A2[2500], S2[50], M[50][50];
  Hilb(A2, 50);
  SolveVector_50(A2, S2);

  for(int c=0; c<50; c++){
    norm = 0.0;
    X2[c] = 1.0-S2[c];
    // printf("det x(%d)=%13.10e\n", c, X[c]);
    norm = fabs(X2[c]);
    // printf("ABS of det x(%d)=%13.10e\n", c, norm);
    if(nor2 <= norm)
      nor2 = norm;
  }
  printf("the norm of x2-x2' is: %13.10e\n", nor2);

  double x2[50], b2[50], b2_[50];
  for(int k=0; k<50; k++)
    x2[k] = 1.0;
  Hilb(A2, 50);
  for(int p=0; p<50; p++)
  for(int q=0; q<50; q++)
    M[p][q] = A2[p*50+q];
  trmul(M, x2, 50, 50, 1, b2);
  trmul(M, S2, 50, 50, 1, b2_);

  for(int e=0; e<50; e++){
    norm = 0.0;
    Y2[e] = b2[e]-b2_[e];
    // printf("det Y(%d)=%13.10e\n", e, Y[e]);
    norm = fabs(Y2[e]);
    // printf("ABS of det Y(%d)=%13.10e\n", e, norm);
    if(Nor2 <= norm)
      Nor2 = norm;
  }
  printf("the norm of b2-b2_' is: %13.10e\n", Nor2);
  printf("\n");
  /**
  * x(0)=1.0000607976e+000
    x(1)=1.0007697305e+000
    x(2)=9.8777107223e-001
    x(3)=1.0280396264e+000
    x(4)=1.0008901925e+000
    x(5)=9.8273707212e-001
    x(6)=9.8205941902e-001
    x(7)=9.9048404134e-001
    x(8)=1.0005778867e+000
    x(9)=1.0084735115e+000
    x(10)=1.0129223111e+000
    x(11)=1.0140872567e+000
    x(12)=1.0127210067e+000
    x(13)=1.0097093749e+000
    x(14)=1.0058539636e+000
    x(15)=1.0017903181e+000
    x(16)=9.9797537393e-001
    x(17)=9.9470623079e-001
    x(18)=9.9215000204e-001
    x(19)=9.9037474929e-001
    x(20)=9.8937707847e-001
    x(21)=9.8910492029e-001
    x(22)=9.8947539105e-001
    x(23)=9.9038827836e-001
    x(24)=9.9173588215e-001
    x(25)=9.9340995235e-001
    x(26)=9.9530638045e-001
    x(27)=9.9732820601e-001
    x(28)=9.9938737629e-001
    x(29)=1.0014056037e+000
    x(30)=1.0033146033e+000
    x(31)=1.0050558899e+000
    x(32)=1.0065803015e+000
    x(33)=1.0078473462e+000
    x(34)=1.0088244606e+000
    x(35)=1.0094862279e+000
    x(36)=1.0098135955e+000
    x(37)=1.0097931218e+000
    x(38)=1.0094162591e+000
    x(39)=1.0086786934e+000
    x(40)=1.0075797389e+000
    x(41)=1.0061217846e+000
    x(42)=1.0043098057e+000
    x(43)=1.0021509206e+000
    x(44)=9.9965400682e-001
    x(45)=9.9682935693e-001
    x(46)=9.9368837833e-001
    x(47)=9.9024334226e-001
    x(48)=9.8650714947e-001
    x(49)=9.8249314359e-001
    the norm of x2-x2' is: 2.8039626429e-002
    the norm of b2-b2_' is: 2.5686291449e-007
  * */

  double nor3=0.0, Nor3=0.0, X3[100], Y3[100], A3[10000], S3[100], N[100][100];
  Hilb(A3, 100);
  SolveVector_100(A3, S3);

  for(int c=0; c<100; c++){
    norm = 0.0;
    X3[c] = 1.0-S3[c];
    // printf("det x(%d)=%13.10e\n", c, X[c]);
    norm = fabs(X3[c]);
    // printf("ABS of det x(%d)=%13.10e\n", c, norm);
    if(nor3 <= norm)
      nor3 = norm;
  }
  printf("the norm of x3-x3' is: %13.10e\n", nor3);

  double x3[100], b3[100], b3_[100];
  for(int k=0; k<100; k++)
    x3[k] = 1.0;
  Hilb(A3, 100);
  for(int p=0; p<100; p++)
  for(int q=0; q<100; q++)
    N[p][q] = A3[p*100+q];
  trmul(N, x3, 100, 100, 1, b3);
  trmul(N, S3, 100, 100, 1, b3_);

  for(int e=0; e<100; e++){
    norm = 0.0;
    Y3[e] = b3[e]-b3_[e];
    // printf("det Y(%d)=%13.10e\n", e, Y[e]);
    norm = fabs(Y3[e]);
    // printf("ABS of det Y(%d)=%13.10e\n", e, norm);
    if(Nor3 <= norm)
      Nor3 = norm;
  }
  printf("the norm of b3-b3_' is: %13.10e\n", Nor3);
  printf("\n");
  /**
   *  x(0)=1.0000351684e+000
      x(1)=9.9694447856e-001
      x(2)=1.0233046964e+000
      x(3)=9.5895912360e-001
      x(4)=9.9304902959e-001
      x(5)=1.0204648218e+000
      x(6)=1.0252498845e+000
      x(7)=1.0165620682e+000
      x(8)=1.0039684267e+000
      x(9)=9.9295875574e-001
      x(10)=9.8569543519e-001
      x(11)=9.8241321387e-001
      x(12)=9.8245170855e-001
      x(13)=9.8486186048e-001
      x(14)=9.8871446981e-001
      x(15)=9.9323196863e-001
      x(16)=9.9782537557e-001
      x(17)=1.0020853598e+000
      x(18)=1.0057544705e+000
      x(19)=1.0086945778e+000
      x(20)=1.0108561375e+000
      x(21)=1.0122519823e+000
      x(22)=1.0129362631e+000
      x(23)=1.0129882529e+000
      x(24)=1.0125003254e+000
      x(25)=1.0115693310e+000
      x(26)=1.0102906408e+000
      x(27)=1.0087542314e+000
      x(28)=1.0070422885e+000
      x(29)=1.0052279098e+000
      x(30)=1.0033746065e+000
      x(31)=1.0015363370e+000
      x(32)=9.9975790259e-001
      x(33)=9.9807556922e-001
      x(34)=9.9651781770e-001
      x(35)=9.9510615326e-001
      x(36)=9.9385591849e-001
      x(37)=9.9277709610e-001
      x(38)=9.9187505662e-001
      x(39)=9.9115126062e-001
      x(40)=9.9060390058e-001
      x(41)=9.9022846059e-001
      x(42)=9.9001824572e-001
      x(43)=9.8996481562e-001
      x(44)=9.9005839062e-001
      x(45)=9.9028818722e-001
      x(46)=9.9064270655e-001
      x(47)=9.9110999845e-001
      x(48)=9.9167786043e-001
      x(49)=9.9233401590e-001
      x(50)=9.9306626972e-001
      x(51)=9.9386262343e-001
      x(52)=9.9471136743e-001
      x(53)=9.9560117274e-001
      x(54)=9.9652113968e-001
      x(55)=9.9746084411e-001
      x(56)=9.9841037894e-001
      x(57)=9.9936037226e-001
      x(58)=1.0003019924e+000
      x(59)=1.0012269740e+000
      x(60)=1.0021275970e+000
      x(61)=1.0029966920e+000
      x(62)=1.0038276325e+000
      x(63)=1.0046143157e+000
      x(64)=1.0053511512e+000
      x(65)=1.0060330430e+000
      x(66)=1.0066553676e+000
      x(67)=1.0072139629e+000
      x(68)=1.0077050902e+000
      x(69)=1.0081254364e+000
      x(70)=1.0084720686e+000
      x(71)=1.0087424320e+000
      x(72)=1.0089343175e+000
      x(73)=1.0090458453e+000
      x(74)=1.0090754454e+000
      x(75)=1.0090218320e+000
      x(76)=1.0088839965e+000
      x(77)=1.0086611729e+000
      x(78)=1.0083528375e+000
      x(79)=1.0079586760e+000
      x(80)=1.0074785799e+000
      x(81)=1.0069126231e+000
      x(82)=1.0062610529e+000
      x(83)=1.0055242709e+000
      x(84)=1.0047028261e+000
      x(85)=1.0037973940e+000
      x(86)=1.0028087754e+000
      x(87)=1.0017378736e+000
      x(88)=1.0005856976e+000
      x(89)=9.9935333995e-001
      x(90)=9.9804197437e-001
      x(91)=9.9665284711e-001
      x(92)=9.9518726437e-001
      x(93)=9.9364659062e-001
      x(94)=9.9203223845e-001
      x(95)=9.9034566060e-001
      x(96)=9.8858835013e-001
      x(97)=9.8676182799e-001
      x(98)=9.8486764256e-001
      x(99)=9.8290735749e-001
      the norm of x3-x3' is: 4.1040876400e-002
      the norm of b3-b3_' is: 2.5711252860e-007
   * */
}