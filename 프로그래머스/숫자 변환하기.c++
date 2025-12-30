#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
int bfs(int x, int y, int n) 
{
    vector<bool>vis(1000001,false);
    queue<pp>q;
    q.push({x,0});
    while(!q.empty())
    {
        pp p=q.front();
        q.pop();
        if (p.first==y)
        {
            return p.second;
        }
        if (0<=p.first+n&&p.first+n<=1000000&&!vis[p.first+n])
        {
            q.push({p.first+n,p.second+1});
            vis[p.first+n]=true;
        }
        if (0<=p.first*2&&p.first*2<=1000000&&!vis[p.first*2])
        {
            q.push({p.first*2,p.second+1});
            vis[p.first*2]=true;
        }
        if (0<=p.first*3&&p.first*3<=1000000&&!vis[p.first*3])
        {
            q.push({p.first*3,p.second+1});
            vis[p.first*3]=true;
        }        
    }
    return -1;
}
int solution(int x, int y, int n) 
{
    int answer=bfs(x,y,n);
    return answer;
}
