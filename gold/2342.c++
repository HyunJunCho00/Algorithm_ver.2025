#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 99999999
using namespace std;
int comp(int f,int t)
{
    if (f==t)return 1;
    if (f==0) return 2;
    if (abs(f-t)==2)return 4;
    return 3;
}
int main(void)
{
    fastIO;vector<int>step;int s,res=INF;
    while(cin>>s,s)step.push_back(s);
    vector<vector<int>>dp(5,vector<int>(5,INF));
    dp[0][0]=0;
    for (int st:step)
    {
        vector<vector<int>>new_dp(5,vector<int>(5,INF));
        for (int i=0;i<5;i++)
        {
            for (int k=0;k<5;k++)
            {
                if (dp[i][k]==INF)continue;
                if (k!=st)
                    new_dp[st][k]=min(new_dp[st][k], dp[i][k] + comp(i, st));
                if (i!=st)
                    new_dp[i][st]=min(new_dp[i][st], dp[i][k] + comp(k, st));
            }
        }
        dp=new_dp;
    }
    for (int i=0;i<5;i++)for (int k=0;k<5;k++)res=min(res,dp[i][k]);
    cout<<res<<'\n';
    return 0;
}
