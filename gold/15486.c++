#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;
    int n,m=0;cin>>n;
    vector<vector<int>>arr(2,vector<int>(n+1,0));
    vector<int>dp(n+2,0);
    for(int i=1;i<=n;i++)
        cin>>arr[0][i]>>arr[1][i];
    for(int i=1;i<=n;i++)
    {
        dp[i]=max(dp[i],dp[i-1]);
        if (i+arr[0][i]<=n+1)
        {
            dp[i+arr[0][i]]=max(dp[i+arr[0][i]],dp[i]+arr[1][i]);
        }
    }
    for(int i=1;i<=n+1;i++)m=max(m,dp[i]);
    cout<<m<<'\n';
    return 0;
}
