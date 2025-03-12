#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<long long int>a(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<vector<long long int>>dp(n,vector<long long int>(21,0));
    dp[1][a[1]]=1;
    for(int i=2;i<n;i++)
    {
        for(int k=0;k<=20;k++)
        {
            if (k-a[i]>=0&&k-a[i]<=20)
                dp[i][k-a[i]]+=dp[i-1][k];
            if (k+a[i]>=0&&k+a[i]<=20)
                dp[i][k+a[i]]+=dp[i-1][k];
        }
    }
    cout<<dp[n-1][a[n]]<<'\n';
    return 0;
}
