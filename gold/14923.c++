#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int x,y,mov,ch;
}que;
int arr[1001][1001];
bool vis[1001][1001][2];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void bfs(int n,int m,int hx,int hy,int ex,int ey)
{
    queue<que> q;
    vis[hx][hy][0]=true;
    q.push({hx,hy,0,0});
    while(!q.empty())
    {
        que qq=q.front();
        if (qq.x==ex&&qq.y==ey)
        {
            cout<<qq.mov;
            exit(0);
        }
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=qq.x+dx[i],y=qq.y+dy[i];
            if (1<=x&&x<=n&&1<=y&&y<=m&&!vis[x][y][qq.ch])
            {
                if (!arr[x][y])
                {
                    q.push({x,y,qq.mov+1,qq.ch});
                    vis[x][y][qq.ch]=true;
                }
                else
                {
                    if (!qq.ch)
                    {
                        q.push({x,y,qq.mov+1,qq.ch+1});
                        vis[x][y][qq.ch+1]=true;
                    }
                }
            }
        }
    }
    cout<<-1;
}
int main(void)
{
    int n,m,hx,hy,ex,ey;
    cin>>n>>m;
    cin>>hx>>hy;
    cin>>ex>>ey;
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=m;k++)
        {
            cin>>arr[i][k];
        }
    }
    bfs(n,m,hx,hy,ex,ey);
    return 0;
}
