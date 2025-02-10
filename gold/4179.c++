#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 99999999
using namespace std;
struct node
{
    int x,y,t; node (int x,int y,int t):x(x),y(y),t(t){};
};
vector<vector<int>>arr;
queue<node>fire;
queue<node>save;
vector<vector<int>>visited;
int c_x[4]={1,0,-1,0};
int c_y[4]={0,-1,0,1};
void bfs(int r,int c)
{
    int f_size=fire.size(),f_start=0,s_size=save.size(),s_start=0;
    while (1)
    {
        int f_add=0,s_add=0;
        for (int i=f_start;i<f_size;i++)
        {
            node cur=fire.front();
            fire.pop();
            int x=cur.x,y=cur.y,t=cur.t;
            visited[x][y]=-1;
            for (int k=0;k<4;k++)
            {
                int x1=x+c_x[k],y1=y+c_y[k];
                if (0<=x1&&x1<r&&0<=y1&&y1<c&&arr[x1][y1]!=INF)
                {
                    if (arr[x1][y1]>=0&&visited[x1][y1]>=0)
                    {
                        arr[x1][y1]=t-1;
                        fire.push(node(x1,y1,arr[x1][y1]));
                        f_add++;
                    }                 
                    visited[x1][y1]=-1;
                }
            }
        }
        f_start=f_size,f_size+=f_add;
        for (int i=s_start;i<s_size;i++)
        {
            node cur=save.front();save.pop();
            int x=cur.x,y=cur.y,t=cur.t; visited[x][y]=1;
            for (int k=0;k<4;k++)
            {
                int x1=x+c_x[k],y1=y+c_y[k];
                if (0<=x1&&x1<r&&0<=y1&&y1<c)
                {
                    if (arr[x1][y1]!=INF)
                    {
                        if (!arr[x1][y1]&&visited[x1][y1]==0)
                        {
                            arr[x1][y1]=t+1;
                            save.push(node(x1,y1,arr[x1][y1]));
                            s_add++;
                        }
                    }
                    visited[x1][y1]=1;
                }
                else
                {
                    cout<<t<<'\n';
                    exit(0);
                }   
            }
        }
        s_start=s_size;s_size+=s_add;
        if (s_start==s_size)
            break;
    }
    cout<<"IMPOSSIBLE"<<'\n';
}
int main(void)
{
    fastIO;int r,c;cin>>r>>c;arr.assign(r,vector<int>(c,0));
    visited.assign(r,vector<int>(c,0));
    int x,y;
    for (int i=0;i<r;i++)
    {
        for (int k=0;k<c;k++)
        {
            char j;cin>>j;
            if (j=='J')
            {
                x=i,y=k;arr[i][k]=1;
                save.push(node(x,y,1));
            }
            else if (j=='F')
            {
                fire.push(node(i,k,-1));
                arr[i][k]=-1;
            }
            else if (j=='#')
                arr[i][k]=INF;
            else
                arr[i][k]=0;
        }
    }
    bfs(r,c);
    return 0;
}
