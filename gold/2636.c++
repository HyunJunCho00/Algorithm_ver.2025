#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
struct node
{
    int x,y;
    node(int x,int y):x(x),y(y){};
};
vector<vector<int>> arr;
queue<node>q;
queue<node>change;
vector<vector<bool>>visited;
int cnt=0,h=0;
stack<int>st;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void bfs(int n,int m)
{
    while (1)
    {
        visited.assign(n,vector<bool>(m,false));
        q.push(node(0,0));
        visited[0][0]=true;
        while(!q.empty())
        {
            node cur=q.front();
            q.pop();
            for (int i=0;i<4;i++)
            {
                int x=cur.x+dir[i][0];
                int y=cur.y+dir[i][1];
                if (0<=x&&x<n&&0<=y&&y<m&&!visited[x][y])
                {
                    if (arr[x][y]==0||arr[x][y]==-1)
                    {
                        q.push(node(x,y));
                        arr[x][y]=-1;
                    }
                    else if (arr[x][y] == 1)
                        change.push(node(x,y));
                    visited[x][y]=true;
                }
            }
        }
        if (change.empty())
            break;
        cnt=cnt-change.size();
        st.push(cnt);
        h++;
        while (!change.empty())
        {
            node cur=change.front();
            change.pop();
            arr[cur.x][cur.y]=-1;
        }
    }
    if (st.size()>1)
        st.pop();
    cout<<h<<'\n'<<st.top()<<'\n';
}
int main(void)
{
    fastIO;
    int n,m;
    cin>>n>>m;
    arr.assign(n,vector<int>(m,0));
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<m;k++)
        {
            cin>>arr[i][k];
            if (arr[i][k])
                cnt++;
        }
    }
    st.push(cnt);
    bfs(n,m); 
    return 0;
}
