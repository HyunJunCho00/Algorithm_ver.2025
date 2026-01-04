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
