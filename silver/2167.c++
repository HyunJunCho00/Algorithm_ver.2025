#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;int n,m,t,x,y,s,e;cin>>n>>m;
    vector<vector<int>>arr(n+1,vector<int>(m+1,0)),dp(n+1,vector<int>(m+1,0));
    for (int i=1;i<=n;i++)
        for (int k=1;k<=m;k++)
        {
            cin>>arr[i][k];
            dp[i][k]=dp[i-1][k]+dp[i][k-1]-dp[i-1][k-1]+arr[i][k];
        }
    cin>>t; stringstream ss;
    for (int i=0;i<t;i++)
    {
        cin>>x>>y>>s>>e;
        ss<<dp[s][e]-dp[x-1][e]-dp[s][y-1]+dp[x-1][y-1]<<'\n';
    }
    cout<<ss.str();
    return 0;
}
