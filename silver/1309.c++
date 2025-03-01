#include <bits/stdc++.h>
#define DIV 9901
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<long long int>dp(n+1,1);dp[1]=3;
    for (int i=2;i<=n;i++) dp[i]=(dp[i-1]*2+dp[i-2])%DIV;
    cout<<dp[n]<<'\n';
    return 0;
}
