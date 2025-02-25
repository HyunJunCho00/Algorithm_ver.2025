#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int main(void)
{
    int n,k;cin>>n>>k;
    vector<vector<int>>dp(k+1,vector<int>(n+1,1));
    for (int i=1;i<=k;i++)dp[i][1]=i;
    for (int i=2;i<=k;i++)for (int j=2;j<=n;j++) dp[i][j]=(dp[i-1][j]+dp[i][j-1])%INF;
    cout<<dp[k][n]<<'\n';
    return 0;
}
