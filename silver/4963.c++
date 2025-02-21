#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using namespace std;
vector<vector<int>>mp;
vector<vector<bool>>visited;
int dx[8]={0,-1,-1,-1,0,1,1,1},dy[8]={-1,-1,0,1,1,1,0,-1};
void bfs(int w,int h)
{
    int area=0;
    queue<pii>q;
    for (int i=0;i<h;i++)
    {
        for (int k=0;k<w;k++)
        {
            if (!visited[i][k]&&mp[i][k])
            {
                area++;
                q.push({i,k});
                visited[i][k]=true;
                while (!q.empty())
                {
                    int x=q.front().first,y=q.front().second;
                    q.pop();
                    for (int z=0;z<8;z++)
                    {
                        int cx=x+dx[z],cy=y+dy[z];
                        if (0<=cx&&cx<h&&0<=cy&&cy<w&&!visited[cx][cy]&&mp[cx][cy])
                        {
                            visited[cx][cy]=true;
                            q.push({cx,cy});
                        }
                    }
                }
            }
        }
    }
    cout<<area<<'\n';
}
int main(void)
{
    fastIO;
    while (1)
    {
        int w=0,h=0;
        cin>>w>>h;
        if (!w&&!h)
            break;
        mp.assign(h,vector<int>(w,0));
        visited.assign(h,vector<bool>(w,false));
        for (int i=0;i<h;i++)for(int k=0;k<w;k++)cin>>mp[i][k];
        bfs(w,h);
    }
    return 0;
}
