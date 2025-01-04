#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
void multiple(long long result[2][2],long long matrix[2][2])
{
    long long int save[2][2]={{0,0},{0,0}};
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++)
        {
            for (int k=0;k<2;k++)
            {
                save[i][j]=(save[i][j]+result[i][k]*matrix[k][j])%MOD;
            }
        }
    }
    for (int i=0;i<2;i++)
    {
        for (int k=0;k<2;k++)
        {
            result[i][k]=save[i][k];
        }
    }
}
void power (long long matrix[2][2],long long int n)
{
    long long int result[2][2]={{1,0},{0,1}};
    while (n>0)
    {
        if (n%2==1)
            multiple(result,matrix);
        multiple(matrix,matrix);
        n/=2;
    }
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++)
        {
            matrix[i][j]=result[i][j];
        }
    }
}
long long int fibonacci(long long n)
{
    if (n<1)
        return n;
    long long int matrix[2][2]={{1,1},{1,0}};
    power(matrix,n);
    return matrix[1][0];
}
int main(void)
{
    long long int n;
    cin>>n;
    cout<<fibonacci(n)<<'\n';
    return 0;
}
