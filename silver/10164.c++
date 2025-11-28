#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m,kk;
    cin>>n>>m>>kk;
    vector<vector<int>>arr(n+1,vector<int>(m+1,0));
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int num=1;
    int x=1,y=1;
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=m;k++)
        {
            arr[i][k]=num;
            if (num==kk)
            {
                x=i,y=k;
            }
            num++;
        }
    }
    for(int i=1;i<=x;i++)
    {
        for(int k=1;k<=y;k++)
        {
            if (i==1&&k==1)
                dp[1][1]=1;
            else
                dp[i][k]=dp[i-1][k]+dp[i][k-1];
        }
    }
    for(int i=x;i<=n;i++)
    {
        for(int k=y;k<=m;k++)
        {
            if (i==1&&k==1)
                dp[1][1]=1;
            else
                dp[i][k]=dp[i-1][k]+dp[i][k-1];
        }
    }
    cout<<dp[n][m];
    return 0;
}
