#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m,res=0;
    cin>>n>>m;
    vector<vector<int>>a(n+1,vector<int>(m+1,0)),dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        for(int k=1;k<=m;k++)
            a[i][k]=s[k-1]-'0';
    }
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=m;k++)
        {
            if (a[i][k])
            {
                dp[i][k]=min({dp[i-1][k-1],dp[i-1][k],dp[i][k-1]})+1;
                res=max(res,dp[i][k]);
            }
        }
    }
    cout<<res*res<<'\n';
    return 0;
}
