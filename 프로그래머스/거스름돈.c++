#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> money) {

    vector<long long int> dp(n+1,0);
    dp[0]=1;
    for(int coin:money)
    {
        for(int i=coin;i<=n;i++)
        {
            dp[i]=(dp[i]+dp[i-coin])%1000000007;
        }
    }
    return dp[n];
}
