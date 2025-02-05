#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;
    int t,w,sum=0;
    cin>>t>>w;
    vector<int>tree(t+1,0);
    vector<vector<int>>dp(t+1,vector<int>(w+1,0));
    for (int i=1;i<=t;i++)
        cin>>tree[i];
    for (int i=1;i<=t;i++)
    {
        for (int k=0;k<=w;k++)
        {
            dp[i][k]=dp[i-1][k]+(tree[i]==(k%2)+1?1:0);
            if (k>0)
                dp[i][k]=max(dp[i][k],dp[i-1][k-1]+(tree[i]==(k%2)+1?1:0));
        }
    }
    for (int i=0;i<=w;i++)
        sum=max(sum,dp[t][i]);
    cout<<sum<<'\n';
    return 0;
}
