#include <bits/stdc++.h>
using namespace std;
int cnt=9;
void dfs(int n,long long res,int dig,int digit,int last)
{
    if (n==cnt&&dig==digit)
    {
        cout<<res;exit(0);
    }
    for(int i=0;i<last;i++)
    {
        long long int next=res*10+i;
        if (digit>=dig+1)
        {
            if (dig+1==digit)cnt++;
            dfs(n,next,dig+1,digit,i);
        }
    }
}
int main(void)
{
    int n;cin>>n;
    if (n<=9)
    {
        cout<<n; return 0;
    }
    for(int i=2;i<=10;i++)
    {
        for(int k=1;k<=9;k++)
        {
            dfs(n,k,1,i,k);
        }
    }
    cout<<-1;
    return 0;
}
