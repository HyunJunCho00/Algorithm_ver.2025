#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int,int>
#define tt tuple<int,int,int>
#define INF 99999999
using namespace std;
vector<vector<int>>arr;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int res=INF;
int find_path(queue<pii>&q,vector<vector<int>>&dist,vector<vector<bool>>&visited,int n,int c)
{
    while (!q.empty())
    {
        pii cur=q.front();q.pop();
        int x=cur.first,y=cur.second;
        visited[x][y]=true;
        for (int z=0;z<4;z++)
        {
            int cx=x+dx[z],cy=y+dy[z];
            if (0<=cx&&cx<n&&0<=cy&&cy<n&&!visited[cx][cy])
            {
                if (!arr[cx][cy])
                {
                    dist[cx][cy]=min(dist[cx][cy],dist[x][y]+1);
                    q.push({cx,cy});
                    visited[cx][y]=true;
                }
                else if (arr[cx][cy]&&c!=arr[cx][cy])
                    return dist[x][y];
            }
        }
    }
    return INF;
}
void bfs(int n,int b)
{
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    queue<pii>q,qq; set<tt>save;
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<n;k++)
        {
            if (!visited[i][k]&&arr[i][k])
            {
                q.push({i,k});
                arr[i][k]=++b;
                visited[i][k]=true;
                while (!q.empty())
                {
                    pii cur=q.front();q.pop();
                    visited[cur.first][cur.second]=true;
                    for (int z=0;z<4;z++)
                    {
                        int cx=cur.first+dx[z],cy=cur.second+dy[z];
                        if (0<=cx&&cx<n&&0<=cy&&cy<n&&!visited[cx][cy])
                        {
                            if (arr[cx][cy])
                            {
                                arr[cx][cy]=arr[cur.first][cur.second];
                                q.push({cx,cy});visited[cx][cy]=true;
                            }
                            else
                                save.insert({cur.first,cur.second,b});
                        }
                    }
                }
            }
        }
    }
    for (const auto& t : save) 
    {
        int a = get<0>(t),b = get<1>(t),c = get<2>(t);
        qq.push({a,b});
        visited.assign(n,vector<bool>(n,false));
        vector<vector<int>>dist(n,vector<int>(n,INF)); 
        dist[a][b]=0;
        res=min(res,find_path(qq,dist,visited,n,c));
        qq=q;
    }
    cout<<res<<'\n';
}
int main(void)
{
    fastIO;int n,c;cin>>n;
    arr.assign(n,vector<int>(n,0));
    for (int i=0;i<n;i++)for(int k=0;k<n;k++)cin>>arr[i][k];
    bfs(n,0);
    return 0;
}
