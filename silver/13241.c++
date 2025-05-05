#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    while(b!=0)
    {
        if (a>b){
            int temp=b;
            b=a%b;
            a=temp;
        }
        else b=b%a;
    }
    return a;
}
int main(void)
{
    long long a,b;
    cin>>a>>b;
    long long c=gcd(a,b);
    cout<<a/c*b;
    return 0;
}
