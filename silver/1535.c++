#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<vector<int>>arr(2,vector<int>(n,0));
    vector<int>dp(101,0);
    for(int i=0;i<2;i++)
    {
        for(int k=0;k<n;k++)
        {
            cin>>arr[i][k];
        }
    }
    for(int i=0;i<n;i++)
    {
        int w=arr[0][i];
        int v=arr[1][i];
        for(int j=99;j>=w;j--)
        {
            dp[j]=max(dp[j],dp[j-w]+v);
        }
    }
    int light=0;
    for(int i=0;i<=99;i++)
        if (dp[i]>light) light=dp[i];
    cout<<light;
    return 0;
}
