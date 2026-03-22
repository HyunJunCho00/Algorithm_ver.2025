#include<bits/stdc++.h>
using namespace std;

int solution(int n) 
{
    vector<long long int>dp(n+1,0);
    dp[0]=1;
    dp[2]=3;
    for(int i=4;i<=n;i+=2)
    {
        for(int k=i-2;k>=0;k-=2)
        {
            if (k==i-2)
            {
                dp[i]=(dp[i]+dp[k]*3)%1000000007;
            }
            else
            {
                dp[i]=(dp[i]+dp[k]*2)%1000000007;
            }
        }
    }
    
    return dp[n];
}
