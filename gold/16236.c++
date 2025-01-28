#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
struct node
{
    int x,y,dist;
    node (int x,int y,int dist) : x(x),y(y),dist(dist){}
};
struct eat
{
    int x,y,dist;
    eat (int x,int y,int dist) : x(x),y(y),dist(dist){}
    bool operator<(const eat&b)const{
        if (dist != b.dist) return dist > b.dist; 
        if (x != b.x) return x > b.x;     
        return y > b.y;  
    }
};
vector <vector<int>> arr;
vector<vector<bool>>visited;
queue <node> q;
priority_queue <eat> pq;
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
void bfs(int x,int y,int n)
{
    int fish_size=2,fish_eaten=0,dist=0;
    while (1)
    {
        q.push(node(x,y,dist));
        visited[x][y]=true;
        while (!q.empty())
        {
            node locate=q.front();
            q.pop();
            for (int i=0;i<4;i++)
            {
                int x1=locate.x+dir[i][0];
                int y1= locate.y+dir[i][1];
                int b_dist=locate.dist+1;
                if (0<=x1&&x1<n&&0<=y1&&y1<n&&!visited[x1][y1])
                {
                    visited[x1][y1]=true;
                    if (arr[x1][y1]>0&&arr[x1][y1]<fish_size)
                        pq.push(eat(x1,y1,b_dist));
                    else if (arr[x1][y1]==0||arr[x1][y1]==fish_size)
                        q.push(node(x1,y1,b_dist));
                }
            }
        }
        if (pq.empty())
            break;
        eat fish=pq.top();
        dist+=fish.dist;
        fish_eaten+=1;
        x=fish.x,y=fish.y,dist=fish.dist;
        arr[x][y]=0;
        if (fish_size==fish_eaten)
        {
            fish_size++;
            fish_eaten=0;
        }
        while (!pq.empty())
            pq.pop();
        visited.assign(n,vector<bool>(n,false));
    }
    cout<<dist<<'\n';
}
int main(void)
{
    fastIO;
    int n;
    cin>>n;
    arr.assign(n,vector<int>(n,0));
    visited.assign(n,vector<bool>(n,false));
    int x,y,m;
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<n;k++)
        {
            cin>>m;
            if (m)
            {
                arr[i][k]=m;
                if (m==9)
                {
                    x=i,y=k;
                    arr[i][k]=0;
                }
            }
        }
    }
    bfs(x,y,n);
    return 0;
}
