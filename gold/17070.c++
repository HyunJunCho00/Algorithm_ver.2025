#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
vector <vector<int>> arr;
struct node
{
    int x,y;
    int dir;
    node(int x,int y,int dir) :x(x),y(y),dir(dir){}
};
queue <node> q;
int change[3][2]={{0,1},{1,1},{1,0}};
//0은 가로, 1은 대각선, 2는 세로
int result=0;
bool check(node cur,int n)
{
    for (int i=0;i<3;i++)
    {
        int x1=cur.x+change[i][0],y1=cur.y+change[i][1];
        if (x1>=n||y1>=n)
        {
            return false;
        }
        else if (arr[x1][y1])
            return false;
    }
    return true;
}
void horizontal(node cur,int n)
{
    int x1=cur.x+change[0][0],y1=cur.y+change[0][1];
    if (x1<n&&y1<n)
    {
        if (!arr[x1][y1])
        {
            q.push(node(x1,y1,0));
        }
    }
}
void vertical(node cur,int n)
{
    int x1=cur.x+change[2][0],y1=cur.y+change[2][1];
    if (x1<n&&y1<n)
    {
        if (!arr[x1][y1])
        {
            q.push(node(x1,y1,2));
        }
    }
}
void diagonal(node cur,int n)
{
    if (check(cur,n)==true)
    {
        q.push(node(cur.x+change[1][0],cur.y+change[1][1],1));
    }
}
void solve(int s,int e,int n)
{
    q.push(node(0,1,0));
    while (!q.empty())
    {
        node cur=q.front();
        q.pop();
        if (cur.x==n-1&&cur.y==n-1)
        {
            result++;
        }
        else
        {
            int dir=cur.dir;
            if (dir==0)
            {
                horizontal(cur,n);
                diagonal(cur,n);
            }
            else if (dir==1)
            {
                horizontal(cur,n);
                diagonal(cur,n);
                vertical(cur,n);
            }
            else
            {
                vertical(cur,n);
                diagonal(cur,n);
            }
        }
    }
    cout<<result<<'\n';
}
int main(void)
{
    fastIO;
    int n;
    cin>>n;
    arr.assign(n,vector<int>(n,0));
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<n;k++)
        {
            cin>>arr[i][k];
        }
    }
    solve(0,1,n);
    return 0;
}
