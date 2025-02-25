#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<int>dp(n+1,0);dp[2]=3;
    for (int i=4;i<=n;i+=2)
    {
        dp[i]+=dp[i-2]*3+2;
        for (int j=i-4;j>=2;j-=2) dp[i]+=2*dp[j];
    }
    cout<<dp[n]<<'\n';
    return 0;
}
