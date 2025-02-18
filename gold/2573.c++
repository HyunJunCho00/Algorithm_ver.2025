#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
struct node
{
    int x,y,t;node(int x,int y,int t):x(x),y(y),t(t){};
};
vector<vector<int>> ice;
vector<vector<bool>>visited;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y,int n,int m)
{
    visited[x][y]=true;
    for (int i=0;i<4;i++)
    {
        int cx=dx[i]+x,cy=dy[i]+y;
        if (0<=cx&&cx<n&&0<=cy&&cy<m&&!visited[cx][cy]&&ice[cx][cy])
            dfs(cx,cy,n,m);
    }
}
int main(void)
{
    fastIO;int n,m,times=0;cin>>n>>m;
    ice.assign(n,vector<int>(m,0));
    for (int i=0;i<n;i++) for (int k=0;k<m;k++) cin>>ice[i][k];
    while (1)
    {
        stack <node>st;
        visited.assign(n,vector<bool>(m,false));
        int div=0,zero=0;
        for (int i=0;i<n;i++)
        {
            for (int k=0;k<m;k++)
            {
                if (!visited[i][k]&&ice[i][k])
                {    
                    dfs(i,k,n,m);
                    div++;
                }
                if (!ice[i][k])
                    zero++;
            }
        }
        if (zero==n*m||div>=2)
        {
            cout<<((zero==n*m)?0:times)<<'\n';
            break;
        }
        for (int i=0;i<n;i++)
        {
            for (int k=0;k<m;k++)
            {
                int cnt=0;
                if (ice[i][k])
                {
                    for (int l=0;l<4;l++)
                    {
                        int cx=dx[l]+i,cy=dy[l]+k;
                        if (0<=cx&&cx<n&&0<=cy&&cy<m&&!ice[cx][cy])
                            cnt++;
                    }
                    int next=(ice[i][k]-cnt<0)?0:ice[i][k]-cnt;
                    st.push(node(i,k,next));
                }
            }
        }
        times++;
        while(!st.empty())
        {
            node cur=st.top();
            ice[cur.x][cur.y]=cur.t;
            st.pop();
        }
    }
    return 0;
}
