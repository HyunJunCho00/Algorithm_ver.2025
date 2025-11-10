#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<vector<int>>arr(n,vector<int>(n,0));
    vector<vector<long long>>dp(n,vector<long long>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n;k++)
        {
            cin>>arr[i][k];
        }
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n;k++)
        {
            if (i==n-1&&k==n-1)
                break;
            int right_mov=i+arr[i][k];
            int down_mov=k+arr[i][k];
            if (right_mov<n) dp[right_mov][k]+=dp[i][k];
            if (down_mov<n) dp[i][down_mov]+=dp[i][k];
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}
