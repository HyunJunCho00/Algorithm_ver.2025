#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
vector <vector<vector<int>>> dp;
vector <vector<int>> arr;
void input(int n)
{
    dp.assign(n,vector<vector<int>>(2,vector<int>(3,0)));
    arr.assign(n,vector<int>(3,0));
    int num=0;
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<3;k++)
        {
            cin>>arr[i][k];
            if (i==0)
            {
                dp[i][0][k]=arr[i][k];
                dp[i][1][k]=arr[i][k];
            }
        }
    }
}
void solve(int n)
{
    for (int i=1;i<n;i++)
    {
        //max 부분 
        dp[i][0][0]=arr[i][0]+ max(dp[i-1][0][0],dp[i-1][0][1]);
        dp[i][0][2]=arr[i][2]+ max(dp[i-1][0][1],dp[i-1][0][2]);
        dp[i][0][1]=arr[i][1]+max(dp[i-1][0][0],dp[i-1][0][2]);
        dp[i][0][1]=max(dp[i][0][1],arr[i][1]+dp[i-1][0][1]);
        //min 부분
        dp[i][1][0]=arr[i][0]+ min(dp[i-1][1][0],dp[i-1][1][1]);
        dp[i][1][2]=arr[i][2]+ min(dp[i-1][1][1],dp[i-1][1][2]);
        dp[i][1][1]=arr[i][1]+min(dp[i-1][1][0],dp[i-1][1][2]);
        dp[i][1][1]=min(dp[i][1][1],arr[i][1]+dp[i-1][1][1]);
    }
    int max_result=max(dp[n-1][0][0],dp[n-1][0][1]); max_result=max(max_result,dp[n-1][0][2]);
    int min_result=min(dp[n-1][1][0],dp[n-1][1][1]); min_result=min(min_result,dp[n-1][1][2]);
    cout<<max_result<<' '<<min_result<<'\n';
}
int main(void)
{
    int n;
    cin>>n;
    input(n);
    solve(n);
    return 0;
}
