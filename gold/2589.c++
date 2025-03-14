#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
vector<vector<int>>arr;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void bfs(int l,int w)
{
    queue<pii>q;
    vector<vector<bool>>vis(l,vector<bool>(w,false));
    vector<vector<int>>dist(l,vector<int>(w,-1));
    int max_size=0;
    for(int i=0;i<l;i++)
    {
        for(int k=0;k<w;k++)
        {
            if (arr[i][k])
            {
                dist.assign(l,vector<int>(w,-1));
                vis.assign(l,vector<bool>(w,false));
                q.push({i,k});vis[i][k]=true;
                dist[i][k]=0;
                while(!q.empty())
                {
                    pii cur=q.front();q.pop();
                    int x=cur.first,y=cur.second;
                    for(int i=0;i<4;i++)
                    {
                        int cx=dx[i]+x,cy=dy[i]+y;
                        if (0<=cx&&cx<l&&0<=cy&&cy<w&&!vis[cx][cy]&&arr[cx][cy])
                        {
                            vis[cx][cy]=true;
                            dist[cx][cy]=dist[x][y]+1;
                            max_size=max(max_size,dist[cx][cy]);
                            q.push({cx,cy});
                        }
                    }
                }
            }
        }
    }
    cout<<max_size<<'\n';
}
int main(void)
{
    int l,w;cin>>l>>w;
    arr.assign(l,vector<int>(w,0));
    for(int i=0;i<l;i++)
    {
        for(int k=0;k<w;k++)
        {
            char c;cin>>c;
            c=='W'?arr[i][k]=0:arr[i][k]=1;
        }
    }
    bfs(l,w);
    return 0;
}
