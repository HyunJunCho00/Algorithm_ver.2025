#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
vector<vector<int>> arr;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int bfs(int n,int m)
{
    int times=0;
    while (1)
    {
        queue<pair<int,int>>q,cheese,change;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        q.push({0,0});
        visited[0][0]=true;
        while (!q.empty())
        {
            pair<int,int>cur=q.front();q.pop();
            int x=cur.first,y=cur.second;
            for (int i=0;i<4;i++)
            {
                int nx=dx[i]+x,ny=dy[i]+y;
                if (0<=nx&&nx<n&&0<=ny&&ny<m&&!visited[nx][ny])
                {
                    visited[nx][ny]=true;
                    if (arr[nx][ny]==0||arr[nx][ny]==-1)
                    {
                        q.push({nx,ny}), arr[nx][ny]=-1;
                    }
                    else 
                        cheese.push({nx,ny});
                }
            }
        }
        if (cheese.empty())
            return times;
        times++;
        while (!cheese.empty())
        {
            pair<int,int> cur=cheese.front();cheese.pop();
            int x=cur.first,y=cur.second;
            int check=0;
            for (int i=0;i<4;i++)
            {
                int nx=x+dx[i],ny=y+dy[i];
                if (0<=nx&&nx<n&&0<=ny&&ny<m&&arr[nx][ny]==-1)
                    check++;
            }
            if (check>=2)
                change.push({x,y});
        }
        while (!change.empty())
        {
            pair<int, int> cur = change.front(); change.pop();
            arr[cur.first][cur.second]=-1;
        }
    }
}
int main(void)
{
    fastIO;
    int n,m;
    cin>>n>>m;
    arr.assign(n,vector<int>(m,0));
    for (int i=0;i<n;i++)
        for (int k=0;k<m;k++)
            cin>>arr[i][k];
    cout<<bfs(n,m)<<'\n';
    return 0;
}
