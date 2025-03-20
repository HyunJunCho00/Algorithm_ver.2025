#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void bfs(int n,int k,int s,int x,int y,vector<vector<int>>&arr,vector<queue<pii>>&m)
{
    queue<pii>q;
    vector<vector<int>>copy_arr;
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    for(int i=0;i<n;i++)
    {
        for(int z=0;z<n;z++)
        {
            if (arr[i][z])
            {
                m[arr[i][z]].push({i,z});
                vis[i][z]=true;
            }
        } 
    }
    for(int time=0;time<s;time++)
    {
        vector<vector<int>>next=arr;
        vector<vector<bool>>next_vis=vis;
        for(int v=1;v<=k;v++)
        {
            queue<pii>&q=m[v];
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                pii cur=q.front();q.pop();
                int xx=cur.first,yy=cur.second;
                for(int j=0;j<4;j++)
                {
                    int cx=xx+dx[j],cy=yy+dy[j];
                    if (0<=cx&&cx<n&&0<=cy&&cy<n&&!next[cx][cy]&&!next_vis[cx][cy])
                    {
                        vis[cx][cy]=true;
                        next[cx][cy]=v;
                        m[v].push({cx,cy});
                    }
                }

            }
        }
        arr=next;
    }
    cout<<arr[x-1][y-1];
}
int main(void)
{
    int n,k;cin>>n>>k;
    vector<vector<int>>arr(n,vector<int>(n,0));
    vector<queue<pii>>virus(k+1);
    for(int i=0;i<n;i++)
    {
        for(int z=0;z<n;z++)
        {
            cin>>arr[i][z];
        } 
    }
    int s,x,y;cin>>s>>x>>y;
    bfs(n,k,s,x,y,arr,virus);
    return 0;
}
