#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void bfs(vector<vector<bool>>&visited,vector<string>&board,string re,int n,int m)
{
    queue<pp>q;
    q.push({0,0});
    visited[0][0]=true;
    while(!q.empty())
    {
        pp p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=dx[i]+p.first,ny=dy[i]+p.second;
            if(0<=nx&&nx<n+2&&0<=ny&&ny<m+2)
            {
                if (!visited[nx][ny]&&board[nx][ny]=='.')
                {
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    
    }
}
int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int n=storage.size();
    int m=storage[0].size();
    vector<string> board(n + 2, string(m + 2, '.'));
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<m;k++)
        {
            board[i+1][k+1]=storage[i][k];
        }
    }
    
    for(string re:requests)
    {
        vector<vector<bool>>visited(n+2,vector<bool>(m+2,false));
        bfs(visited,board,re,n,m);
        queue<pp>q;
        for(int i=1;i<=n;i++)
        {
            for(int k=1;k<=m;k++)
            {
                if(board[i][k]==re[0])
                {
                    if (re.length()==2)
                    {
                        q.push({i,k});
                    }
                    else
                    {
                        if(visited[i][k+1]||visited[i][k-1]||visited[i-1][k]||visited[i+1][k])
                        {
                            q.push({i,k});
                        }
                    }
                }
            }
        }
        
        while(!q.empty())
        {
            pp p=q.front();
            q.pop();
            board[p.first][p.second]='.';
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=m;k++)
        {
            if(board[i][k]!='.')
                answer++;
            cout<<board[i][k]<<' ';
        }
    }
    return answer;
}
