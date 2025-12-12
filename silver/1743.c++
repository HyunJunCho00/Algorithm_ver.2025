#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
int max_size=0;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void bfs(int i,int k,int n,int m,vector<vector<int>>&arr,vector<vector<bool>>&vis)
{
    vis[i][k]=true;
    int cur_size=1;
    queue<pp>q;
    q.push({i,k});
    while(!q.empty())
    {
        pp p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=dx[i]+p.first,ny=dy[i]+p.second;
            if (1<=nx&&nx<=n&&1<=ny&&ny<=m&&!vis[nx][ny]&&arr[nx][ny])
            {
                q.push({nx,ny});
                vis[nx][ny]=true;
                cur_size++;
            }
        }
    }
    max_size=max(max_size,cur_size);
}
int main(void)
{
    int n,m,k,r,c;
    cin>>n>>m>>k;
    vector<vector<int>>arr(n+1,vector<int>(m+1,0));
    for(int i=0;i<k;i++)
    {
        cin>>r>>c;
        arr[r][c]=1;
    }
    vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=m;k++)
        {
            if (!vis[i][k]&&arr[i][k]==1)
            {
                bfs(i,k,n,m,arr,vis);
            }
        }
    }
    cout<<max_size;
    return 0;
}
