#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
vector <vector<int>> arr;
vector<vector<bool>>visited;
int max_size=0;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int t_shape[4][4][2]=
{{{0,0},{0,1},{0,2},{1,1}},
{{0,0},{0,1},{0,2},{-1,1}},
{{0,0},{1,0},{2,0},{1,1}},
{{0,0},{1,0},{2,0},{1,-1}}};
void valid_t_shape(int i,int k,int n,int m)
{
    for (int a=0;a<4;a++)
    {
        int sum=0;
        bool valid=true;
        for (int b=0;b<4;b++)
        {
            int x=i+t_shape[a][b][0];
            int y=k+t_shape[a][b][1];
            if (0<=x&&x<n&&0<=y&&y<m)
            {
                sum+=arr[x][y];
            }
            else
            {
                valid=false;
                break;
            }
        }
        if (valid)
            max_size=max(max_size,sum);
    }
}
void dfs(int i,int k,int sum,int cnt,int n,int m)
{
    if (cnt==4)
    {
        max_size=max(max_size,sum);
        return;
    }
    for (int a=0;a<4;a++)
    {
        int x=i+dir[a][0];
        int y=k+dir[a][1];
        if (0<=x&&x<n&&0<=y&&y<m&&!visited[x][y])
        {
            visited[x][y]=true;
            dfs(x,y,sum+arr[x][y],cnt+1,n,m);
            visited[x][y]=false;
        }
    }
}
int main(void)
{
    fastIO;
    int n,m;
    cin>>n>>m;
    arr.assign(n,vector<int>(m,0));
    visited.assign(n,vector<bool>(m,false));
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<m;k++)
        {
            cin>>arr[i][k];
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<m;k++)
        {   visited[i][k]=true;
            dfs(i,k,arr[i][k],1,n,m);
            visited[i][k]=false;
            valid_t_shape(i,k,n,m);
        }
    }
    cout<<max_size<<'\n';
    return 0;
}
