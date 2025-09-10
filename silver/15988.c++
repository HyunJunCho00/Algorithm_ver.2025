#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;cin>>n;
        vector<long long> dp(n+1,0);
        dp[1]=1;
        if (n>=2) dp[2]=2;
        if (n>=3) dp[3]=4;
        for(int i=4;i<=n;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%1000000009;
        }
        cout<<dp[n]<<'\n';
    }
    return 0;
}
