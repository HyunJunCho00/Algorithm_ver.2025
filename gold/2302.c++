#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m;cin>>n>>m;
    vector<int>dp(n+1,1);
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    int res=1,s=1,e;
    for(int i=0;i<m;i++)
    {
        cin>>e;
        res*=dp[e-s];
        s=e+1;
    }
    res*=dp[n-e];
    cout<<res;
    return 0;
}
