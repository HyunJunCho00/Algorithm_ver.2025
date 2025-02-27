#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main(void)
{
    fastIO;int n,res=-100000000;cin>>n;
    vector<int>dp(n+1,-1001),sum(n+1,-1001),del(n+1,-1001);
    for (int i=1;i<=n;i++)
    {
        cin>>dp[i];
        sum[i]=max(sum[i-1]+dp[i],dp[i]);
        del[i]=max(del[i-1]+dp[i],sum[i-1]);
    }
    for(int i=1;i<=n;i++) res=max({res,del[i],sum[i]});
    cout<<res<<'\n';
    return 0;
}
