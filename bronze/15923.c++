#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;cin>>t;
    while(t--)
    {
        int a,b,n=1,s=0,c=512;cin>>a>>b;
        while(a>n*(n+1)/2)n++;
        a==0||a>21?s=0:(n==1||n==4?(n==1?s=500:s=50):(n==2||n==5)?(n==2?s=300:s=30):n==3?s=200:s=10);
        n=1;
        while(b>=n)
        {
            n*=2;c/=2;
        }
        cout<<(s+(b>0&&b<32?c*2:0))*10000<<'\n';
    }
    return 0;
}
