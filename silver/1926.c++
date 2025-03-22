#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(void)
{
    fastIO;
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<m;k++)
        {
            cin>>arr[i][k];
        }
    }
    queue<pii>q;
    int max_size=0,pic=0;
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<m;k++)
        {
            if (arr[i][k]&&!vis[i][k])
            {
                pic++;
                q.push({i,k});
                int cnt=1;
                vis[i][k]=true;
                while(!q.empty())
                {
                    pii cur=q.front();q.pop();
                    int x=cur.first,y=cur.second;
                    for(int z=0;z<4;z++)
                    {
                        int xx=x+dx[z],yy=y+dy[z];
                        if (0<=xx&&xx<n&&0<=yy&&yy<m&&arr[xx][yy]&&!vis[xx][yy])
                        {
                            cnt++;q.push({xx,yy});
                            vis[xx][yy]=true;
                        }
                    }
                }
                max_size=max(max_size,cnt);
            }
        }
    }
    cout<<pic<<'\n'<<max_size;
    return 0;
}
