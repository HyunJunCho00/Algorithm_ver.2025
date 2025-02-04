#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin>>n;
    vector <long long int>dp(n+1,0);dp[2]=1;
    for (int i=3;i<=n;i++)
    {
        dp[i]=(i-1)*(dp[i-1]+dp[i-2])%1000000000;
    }
    cout<<dp[n]<<'\n';
    return 0;
}
