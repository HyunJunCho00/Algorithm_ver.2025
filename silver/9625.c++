#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int k;cin>>k;
    vector<vector<int>>dp(k+1,vector<int>(2,0));
    dp[0][0]=1;dp[0][1]=0;
    for(int i=1;i<=k;i++)
    {
        dp[i][0]=dp[i-1][1];
        dp[i][1]=dp[i-1][1]+dp[i-1][0];
    }
    cout<<dp[k][0]<<' '<<dp[k][1];
    return 0;
}
