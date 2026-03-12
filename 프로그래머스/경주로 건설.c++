#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef struct node
{
    int x,y,dir;
}di;
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
int solution(vector<vector<int>> board) 
{
    int answer=INF;
    int n=board.size(),m=board[0].size();
    vector<vector<vector<int>>>dist(n,vector<vector<int>>(m,vector<int>(4,INF))); 
    queue<di>q;
    for(int i=0;i<4;i++)
    {
        dist[0][0][i]=0;
        q.push({0,0,i});
    }

    while(!q.empty())
    {
        di d=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=dx[i]+d.x,ny=dy[i]+d.y,dir=d.dir;
            if (0<=nx&&nx<n&&0<=ny&&ny<m&&!board[nx][ny])
            {
                int cost=(dir==i?100:600);
                if (dist[nx][ny][i]>dist[d.x][d.y][dir]+cost)
                {
                    dist[nx][ny][i]=dist[d.x][d.y][dir]+cost;
                    q.push({nx,ny,i});
                }
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        answer=min(answer,dist[n-1][m-1][i]);
    }
    return answer;
}
