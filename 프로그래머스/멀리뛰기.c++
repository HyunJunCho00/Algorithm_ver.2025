#include<bits/stdc++.h>
#define INF 1234567
using namespace std;

long long solution(int n) {
    vector<long long>dp(n+1,0);
    dp[1]=1;
    if (n>=2) dp[2]=1;
    for(int i=1;i<=n-1;i++)
    {
        if (i+1<=n)
        {
            dp[i+1]=(dp[i+1]+dp[i])%INF;
        }
        if (i+2<=n)
        {
            dp[i+2]=(dp[i+2]+dp[i])%INF;
        }
    }
    return dp[n];
}
