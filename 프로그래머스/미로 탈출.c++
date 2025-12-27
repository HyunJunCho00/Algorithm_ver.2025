#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int bfs(vector<string> maps,int d,char target,char start)
{
    int n=maps.size();
    int m=maps[0].size();
    int sx,sy,ex,ey;
    queue<pp>q;
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<m;k++)
        {
            if (maps[i][k]==target)
            {
                ex=i,ey=k;
            }
            else if (maps[i][k]==start)
            {
                sx=i,sy=k;
            }
        }
    }
    dp[sx][sy]=d;
    q.push({sx,sy});
    while(!q.empty())
    {
        pp p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=dx[i]+p.first,ny=dy[i]+p.second;
            if (0<=nx&&nx<n&&0<=ny&&ny<m)
            {
                if (!vis[nx][ny]&&maps[nx][ny]!='X')
                {
                    vis[nx][ny]=true;
                    dp[nx][ny]=dp[p.first][p.second]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    return dp[ex][ey];
}
int solution(vector<string> maps) 
{
    int tar=bfs(maps,0,'L','S');
    if (tar==-1) return -1;
    int tar1=bfs(maps,tar,'E','L');
    if (tar1==-1) return -1;
    return tar1;
}
