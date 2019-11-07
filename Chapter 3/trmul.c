/**
 * 实矩阵相乘
 * double a[m][n] 存放矩阵A的元素
 * double b[n][k] 存放矩阵B的元素
 * int m 矩阵A与乘积矩阵C的行数
 * int n 矩阵A的列数，矩阵B的行数
 * int k 矩阵B与乘积矩阵C的列数
 * double c[m][k] 返回乘积矩阵C=AB的元素
 * */
void trmul(a, b, m, n, k, c)
int m, n, k;
double a[], b[], c[];
{
    int i, j, l, u;
    for(i=0; i<=m-1; i++)
    for(j=0; j<=k-1; j++){
        u = i*k+j;
        c[u] = 0.0;
        for(l=0; l<=n-1; l++)
            c[u] = c[u] + a[i*n+l]*b[l*k+j];
    }
    return;
}