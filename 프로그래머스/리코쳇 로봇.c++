#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int s,e,move;
}mov;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int bfs(vector<string>board)
{

    int s,e,n=board.size(),m=board[0].size();
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<m;k++)
        {
            if (board[i][k]=='R')
            {
                s=i;e=k;
            }
        }
    }
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    queue<mov>q;
    q.push({s,e,0});
    vis[s][e]=true;
    while(!q.empty())
    {
        mov p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=dx[i]+p.s,ny=dy[i]+p.e,nm=p.move;
            while(0<=nx&&nx<n&&0<=ny&&ny<m&&board[nx][ny]!='D')
            {
                nx+=dx[i],ny+=dy[i];
            }
            if (board[nx-dx[i]][ny-dy[i]]=='G')
                return p.move+1;
            if (!vis[nx-dx[i]][ny-dy[i]])
            {
                vis[nx-dx[i]][ny-dy[i]]=true;
                q.push({nx-dx[i],ny-dy[i],nm+1});     
            }
        }
    }
    return -1;
}
int solution(vector<string> board) {
    
    return bfs(board);
}
