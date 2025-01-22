#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define mod 10007
using namespace std;
int main(void)
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>>dp;
    dp.assign(n+1,vector<int>(n+1,1));
    for (int i=1;i<=n;i++)
    {
        for (int k=i;k>0;k--)
        {
            if (i==k)
                continue;
            dp[i][k]=(dp[i-1][k-1]+dp[i-1][k])%mod;
        }
    }
    cout<<dp[n][k]<<'\n';
    return 0;
}
