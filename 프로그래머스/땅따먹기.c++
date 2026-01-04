#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int>>dp(land.size(),vector<int>(land[0].size(),0));
    for(int i=0;i<land[0].size();i++)
    {
        dp[0][i]=land[0][i];
    }
    for(int i=1;i<land.size();i++)
    {
        for(int k=0;k<land[0].size();k++)
        {
            for(int z=0;z<land[0].size();z++)
            {
                if (z!=k)
                    dp[i][k]=max(dp[i][k],dp[i-1][z]);
            }
            dp[i][k]+=land[i][k];
        }
    }
    for(int i=0;i<land[0].size();i++)
    {
        answer=max(answer,dp[land.size()-1][i]);
    }
    return answer;
}

//// 다른 방법 
    int n=land.size();
    for(int i=1;i<n;i++)
    {
        land[i][0]+=max({land[i-1][1],land[i-1][2],land[i-1][3]});
        land[i][1]+=max({land[i-1][0],land[i-1][2],land[i-1][3]});
        land[i][2]+=max({land[i-1][0],land[i-1][1],land[i-1][3]});
        land[i][3]+=max({land[i-1][0],land[i-1][1],land[i-1][2]});
    }
    return *max_element(land[n-1].begin(),land[n-1].end()); 
