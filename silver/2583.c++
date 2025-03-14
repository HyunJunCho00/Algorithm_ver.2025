#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int cx[4]={1,0,-1,0};
int cy[4]={0,1,0,-1};
void bfs(vector<vector<int>>&arr,int m,int n)
{
    vector<vector<bool>>vis(m,vector<bool>(n,false));
    vector<int>save;
    queue<pii>q;
    for(int i=0;i<m;i++)
    {
        for(int k=0;k<n;k++)
        {
            if (!arr[i][k]&&!vis[i][k])
            {
                q.push({i,k});
                vis[i][k]=true;
                int area=1;
                while(!q.empty())
                {
                    pii cur=q.front();q.pop();
                    int x=cur.first,y=cur.second;
                    for(int i=0;i<4;i++)
                    {
                        int dx=x+cx[i],dy=y+cy[i];
                        if(0<=dx&&dx<m&&0<=dy&&dy<n&&!arr[dx][dy]&&!vis[dx][dy])
                        {
                            q.push({dx,dy});vis[dx][dy]=true;area++;
                        }
                    }
                }
                save.push_back(area);
            }
        }
    }
    sort(save.begin(),save.end());
    cout<<save.size()<<'\n';
    for(int s:save)
        cout<<s<<' ';
}
int main(void)
{
    int m,n,k;
    cin>>m>>n>>k;
    vector<vector<int>>arr(m,vector<int>(n,0));
    for (int i=0;i<k;i++)
    {
        int x,y,x1,y1;
        cin>>y>>x>>y1>>x1;
        x=m-x;x1=m-x1;
        for(int z=x1;z<x;z++)
        {
            for(int v=y;v<y1;v++)
            {
                arr[z][v]=1;
            }
        }
    }
    bfs(arr,m,n);
    return 0;
}
