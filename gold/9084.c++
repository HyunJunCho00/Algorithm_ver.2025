#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m;cin>>n;
        vector<int>coin(n,0);
        for(int k=0;k<n;k++)cin>>coin[k];
        cin>>m;
        vector<int>dp(m+1,0);dp[0]=1;
        for(int k=0;k<n;k++)
        {
            for(int z=coin[k];z<=m;z++)
            {
                dp[z]+=dp[z-coin[k]];
            }
        }
        cout<<dp[m]<<'\n';
    }
    return 0;
}
