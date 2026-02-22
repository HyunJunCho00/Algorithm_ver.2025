#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int x,y;
}cor;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void bfs(vector<string>maps, vector<int>&answer,vector<vector<bool>>&vis,int x,int y)
{

    queue<cor> q;
    queue<cor> save;
    q.push({x,y});
    save.push({x,y});
    vis[x][y]=true;
    while(!q.empty())
    {
        cor cur=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=dx[i]+cur.x,ny=dy[i]+cur.y;
            if (0<=nx&&nx<maps.size()&&0<=ny&&ny<maps[0].size()&&maps[nx][ny]!='X'&&!vis[nx][ny])
            {
                save.push({nx,ny});
                q.push({nx,ny});
                vis[nx][ny]=true;
            }
        }
    }
    if (save.empty())
        return;
    int num=0;
    while(!save.empty())
    {
        cor s=save.front();
        save.pop();
        num+=(maps[s.x][s.y])-'0';
    }
    answer.push_back(num);
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>>vis(maps.size(),vector<bool>(maps[0].size(),false));
    for(int i=0;i<maps.size();i++)
    {
        for(int k=0;k<maps[i].size();k++)
        {
            if (maps[i][k]!='X'&&!vis[i][k])
            {
                bfs(maps,answer,vis,i,k);
            }
        }
    }
    if (answer.size())
        sort(answer.begin(),answer.end());
    else
        answer.push_back(-1);
    return answer;
}
