#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
using namespace std;
vector <vector<int>> arr,dp;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int dfs(int x,int y,int m,int n)
{
    if (x==m-1&&y==n-1)
        return 1;
    if (dp[x][y]!=-1)
        return dp[x][y];
    dp[x][y]=0;
    for (int i=0;i<4;i++)
    {
        int cx=x+dx[i],cy=y+dy[i];
        if (0<=cx&&cx<m&&0<=cy&&cy<n&&arr[x][y]>arr[cx][cy])
            dp[x][y]+=dfs(cx,cy,m,n);
    }
    return dp[x][y];
}
int main(void)
{
    fastIO;int m,n;cin>>m>>n;arr.assign(m,vector<int>(n,0)),dp.assign(m,vector<int>(n,-1));
    for (int i=0;i<m;i++) for (int k=0;k<n;k++) cin>>arr[i][k];
    cout<< dfs(0,0,m,n)<<'\n';
    return 0;
}
