#include<bits/stdc++.h>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) 
{

    vector<vector<int>>arr(n+1,vector<int>(m+1,0));
    for(int i=0;i<puddles.size();i++)
    {
        int x=puddles[i][1],y=puddles[i][0];
        arr[x][y]=1;
    }
    vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
    for(int i=1;i<=m;i++)
    {
        if (!arr[1][i]) dp[1][i]=1;
        else break;
    }
    for(int i=1;i<=n;i++)
    {
        if (!arr[i][1]) dp[i][1]=1;
        else break;
    }
    for(int i=2;i<=n;i++)
    {
        for(int k=2;k<=m;k++)
        {
            if (!arr[i][k])
            {
                dp[i][k]=(dp[i-1][k]+dp[i][k-1])%1000000007;
            }
        }
    }
    
    return dp[n][m];
}
