#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
long long int count(long long int n)
{
    long long int cnt=0;
    long long int bit=1;
    while (bit<=n)
    {
        cnt+=(n/(bit*2))*bit;
        long long int check=n%(bit*2)-bit+1;
        if (check>=0)
            cnt+=check;
        bit<<=1;
    }
    return cnt;
}
int main(void)
{
    fastIO;
    long long int a,b;
    cin>>a>>b;
    cout<<count(b)-count(a-1)<<'\n';
    return 0;
}
