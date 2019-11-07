#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double y1(double x){
    double z;
    z = fabs(log(1.0+x)-
    (1.0*x- x*x/2 + x*x*x/3 - pow(x, 4)/4 + pow(x, 5)/5 - 
    pow(x, 6)/6 + pow(x, 7)/7 - pow(x, 8)/8 + pow(x, 9)/9 - pow(x, 10)/10));
    return (z);
}

double y2(double x){
    double z;
    z = fabs(log(1.0/(1.0+x)) - 
    (-1.0*x +  x*x/2 - x*x*x/3 + pow(x, 4)/4 - pow(x, 5)/5 + 
    pow(x, 6)/6 - pow(x, 7)/7 + pow(x, 8)/8 - pow(x, 9)/9 + pow(x, 10)/10));
    return (z);
}

double y3(double x){
    double z;
    z = fabs(log((1.0+x)/(1.0-x))-
    (2.0*x + 2.0*x*x*x/3 + 2.0*pow(x, 5)/5 + 2.0*pow(x, 7)/7 + 2.0*pow(x, 9)/9));
    return (z);
}

double S10_1(double x){
    double m = 0.0;
    m = 1.0*x - x*x/2 + x*x*x/3 - pow(x, 4)/4 + pow(x, 5)/5 - 
    pow(x, 6)/6 + pow(x, 7)/7 - pow(x, 8)/8 + pow(x, 9)/9 - pow(x, 10)/10;
    return m;
}

double S10_2(double x){
    double m = 0.0;
    m = -1.0*x +  x*x/2 - x*x*x/3 + pow(x, 4)/4 - pow(x, 5)/5 + 
    pow(x, 6)/6 - pow(x, 7)/7 + pow(x, 8)/8 - pow(x, 9)/9 + pow(x, 10)/10;
    return m;
}

double S10_3(double x){
    double n = 0.0;
    n = 2.0*x + 2.0*x*x*x/3 + 2.0*pow(x, 5)/5 + 2.0*pow(x, 7)/7 + 2.0*pow(x, 9)/9;
    return (n);
}

void main(){
    double S1=0.0;
    for(int i=1; i<11; i++){
        if(i%2==1){
            S1 += 1.0/i;
            printf("S(%d)=%13.10e\n", i, S1);
        }else{
            S1 -= 1.0/i;
            printf("S(%d)=%13.10e\n", i, S1);
        }
    }
    printf("THE VALUES OF S(10): %13.10e\n", S1);
    printf("\n");
    printf("THE VALUE S10_1(1) IS: %13.10e\n",S10_1(1.0));
    // double NUM =  F1(1.0);
    // ln2=0.69314718055995; S10_1=0.6456349; det=0.04751226<0.5*10^(-1) -> 1位有效数字 0.6？
    // printf("THE FUNCTION RESULT IS: %13.6e\n", NUM);
    double x1=0.0, step=0.0000001, temp1=0.0;
    while(x1<=1.0){
        if(temp1<=y1(x1))
            temp1=y1(x1);
        x1 = x1 + step;
    }
    printf("THE VALUES OF MAX DELT(1): %13.10e\n", temp1);
    printf("\n");


    double S2=0.0;
    for(int i=1; i<11; i++){
        if(i%2==0){
            S2 += 1.0/i * pow(-0.5, i);
            printf("S(%d)=%13.10e\n", i, S2);
        }else{
            S2 -= 1.0/i * pow(-0.5, i);
            printf("S(%d)=%13.10e\n", i, S2);
        }
    }
    printf("THE VALUES OF S2(-0.5): %13.10e\n", S2);
    printf("\n");
    printf("THE VALUE S10_2(-0.5) IS: %13.10e\n",S10_2(-0.5));
    // ln2=0.69314718055995; S10_2=0.6930649; det=0.0000822806<0.5*10^(-3) -> 3位有效数字 0.693？
    double x2=-0.5, temp2=0.0;
    while(x2<=0.5){
        if(temp2<=y2(x2))
            temp2=y2(x2);
        x2 = x2 + step;
    }
    printf("THE VALUES OF MAX DELT(-0.5): %13.10e\n", temp2);
    printf("\n");


    double S3=0.0;
    for(int i=1; i<11; i++){
        if(i%2==1){
            S3 += 2.0* pow(1.0/3, i)/i ;
            printf("S(%d)=%13.10e\n", i, S3);
        }
    }
    printf("THE VALUES OF S3(-0.333): %13.10e\n", S3);
    printf("\n");
    printf("THE VALUE S10_3(-0.333) IS: %13.10e\n",S10_3(1.0/3));
    // ln2=0.69314718055995; S10_3=0.69314604739; det=0.0000011332<0.5*10^(-5) -> 5位有效数字 0.69314？
    double x3=-1.0/3, temp3=0.0;
    while(x3<=1.0/3){
        if(temp3<=y3(x3))
            temp3=y3(x3);
        x3 = x3 + step;
    }
    printf("THE VALUES OF MAX DELT(-0.333): %13.10e\n", temp3);
    printf("\n");

    return;
}

