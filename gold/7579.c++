#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;int n,m,res=1111111111;cin>>n>>m;
    vector<int>dp(10001,-1),mem(n,0),cost(n,0);dp[0]=0;
    for (int i=0;i<n;i++) cin>>mem[i];
    for (int i=0;i<n;i++) cin>>cost[i];
    for (int i=0;i<n;i++)
    {
        for (int j=10000;j>=cost[i];j--)
            if (dp[j-cost[i]]!=-1)
                dp[j]=max(dp[j],dp[j-cost[i]]+mem[i]);
    }
    for (int j=0;j<=10000;j++)
        if (dp[j]>=m)
            res=min(res,j);
    cout<<res<<'\n';
    return 0;
}
