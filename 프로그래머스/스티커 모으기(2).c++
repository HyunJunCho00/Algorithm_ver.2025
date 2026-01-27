#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> dp)
{
    int n=dp.size();
    vector<int>dp1(n,0),dp2(n,0);
    if (n==1)return dp[0];
    dp1[0]=dp[0],dp1[1]=dp[0];
    dp2[1]=dp[1];
    dp2[2]=max(dp[2],dp[1]);
    for(int i=2;i<n-1;i++)
    {
        dp1[i]=max(dp[i]+dp1[i-2],dp1[i-1]);
    }
    for(int i=3;i<n;i++)
    {
        dp2[i]=max(dp[i]+dp2[i-2],dp2[i-1]);
    }
    
    return dp1[n-2]>dp2[n-1]?dp1[n-2]:dp2[n-1];
}
