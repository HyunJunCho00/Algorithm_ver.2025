#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long a,long long b)
{
    while(b)
    {
        if (a>b)
        {
            long long int temp=a;
            a=b;
            b=temp%b;
        }
        else b=b%a;
    }
    return a;
}
int main(void)
{
    long long int a,b;
    cin>>a>>b;
    for(int i=0;i<gcd(a,b);i++) cout<<1;
    return 0;
}
