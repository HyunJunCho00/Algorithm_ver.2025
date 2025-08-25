#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int arr[501][501];
int mov=0;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int dfs(int n,int x,int y,vector<vector<int>>& vis)
{
    if (vis[x][y]>1)
        return vis[x][y];
    for(int i=0;i<4;i++)
    {
        int nx=dx[i]+x,ny=dy[i]+y;
        if (nx>=0&&nx<n&&ny>=0&&ny<n&&arr[nx][ny]>arr[x][y])
            vis[x][y]=max(vis[x][y],dfs(n,nx,ny,vis)+1);
    }
    return vis[x][y];
}
int main(void)
{
    fastIO;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n;k++)
        {
            cin>>arr[i][k];
        }
    }
    vector<vector<int>>vis(n,vector<int>(n,1));
    for(int i=0;i<n;i++)
    {
        for (int k=0;k<n;k++)
        {
            mov=max(mov,dfs(n,i,k,vis));
        }
    }
    cout<<mov;
    return 0;
}
