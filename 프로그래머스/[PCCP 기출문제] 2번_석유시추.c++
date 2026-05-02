#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
unordered_map<int,vector<int>>um;
void bfs(vector<vector<int>>&land,vector<vector<bool>>&visited,int w,int h,int i,int k)
{
    vector<pp>save;
    queue<pp>q;
    q.push({i,k});
    save.push_back({i,k});
    visited[i][k]=true;
    while(!q.empty())
    {
        pp qq=q.front();
        q.pop();
        for(int l=0;l<4;l++)
        {
            int nx=dx[l]+qq.first,ny=dy[l]+qq.second;
            if(0<=nx&&nx<h&&0<=ny&&ny<w&&!visited[nx][ny]&&land[nx][ny])
            {
                visited[nx][ny]=true;
                q.push({nx,ny});
                save.push_back({nx,ny});
            }
        }
    }
    int size=save.size();
    unordered_set<int>us;
    for(auto&s:save)
    {
        land[s.first][s.second]=size;
        if (us.find(s.second)==us.end())
        {
            us.insert(s.second);
            um[s.second].push_back(size);
        }
            
    } 
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    int w=land[0].size();
    int h=land.size();
    vector<vector<bool>>visited(h,vector<bool>(w,false));
    for(int i=0;i<h;i++)
    {
        for(int k=0;k<w;k++)
        {
            if(!visited[i][k]&&land[i][k])
            {
                bfs(land,visited,w,h,i,k);
            }
        }
    }
    for(auto&umm:um)
    {
        int total=0;
        for(auto&s:umm.second)
        {
            total+=s;
        }
        answer=max(answer,total);
    }
    return answer;
}
