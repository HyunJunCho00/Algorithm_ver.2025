#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;long long int sum=0;
    vector<vector<int>>dp(n+1,vector<int>(10,0));
    for (int i=0;i<10;i++) dp[1][i]=1;
    for (int i=2;i<=n;i++)
        for (int k=0;k<10;k++)
            for (int l=0;l<=k;l++)
                dp[i][k]=(dp[i][k]+dp[i-1][l])%10007;
    for (int i=0;i<10;i++) sum+=dp[n][i];
    cout<<sum%10007<<'\n';
    return 0;
}
