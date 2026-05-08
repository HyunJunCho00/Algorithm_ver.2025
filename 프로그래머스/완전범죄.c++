#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {

    vector<int>dp(m,INF);
    dp[0]=0;
    for(int i=0;i<info.size();i++)
    {
        int a=info[i][0];
        int b=info[i][1];
        vector<int>next_dp(m,INF);
        for(int k=0;k<m;k++)
        {
            if(dp[k]==INF)continue;
            
            if(dp[k]+a<n)
            {
                next_dp[k]=min(next_dp[k],dp[k]+a);
            }
            if(k+b<m)
            {
                next_dp[k+b]=min(next_dp[k+b],dp[k]);
            }
        }
        dp=next_dp;
    }
    auto value=min_element(dp.begin(),dp.end());
    return *value==INF?-1:*value;
}
