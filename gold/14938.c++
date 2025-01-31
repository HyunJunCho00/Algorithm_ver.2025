#include <bits/stdc++.h>
#define fastIO ios:: sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define INF 999999999
using namespace std;
struct node
{
    int e,v;
    node (int e,int v): e(e),v(v){};
    bool operator<(const node& b)const
    {
        return v>b.v;
    }
};
priority_queue<node,vector<node>> pq;
vector <int>value;
vector<vector<int>> dijk;
vector <int> dist;
void dijkstra(int s,int n)
{
    dist.assign(n+1,INF);
    dist[s]=0;
    pq.push(node(s,0));
    while (!pq.empty())
    {
        node m=pq.top();
        pq.pop();
        int e=m.e;
        int w=m.v;
        for (int i=1;i<=n;i++)
        {
            if (i==s)
                continue;
            if (dist[i]>w+dijk[e][i])
            {
                dist[i]=w+dijk[e][i];
                pq.push(node(i,dist[i]));
            }
        }
    }
}
int main(void)
{
    fastIO;
    int n,m,r;
    cin>>n>>m>>r;
    dijk.assign(n+1,vector<int>(n+1,INF));
    value.assign(n+1,0);
    for (int i=1;i<=n;i++)
        cin>>value[i];
    for (int i=0;i<r;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dijk[a][b]=c;
        dijk[b][a]=c;
    }
    int max_item=0;
    for (int i=1;i<=n;i++)
    {
        dijkstra(i,n);
        int item=0;
        for (int k=1;k<=n;k++)
        {
            if (dist[k]<=m)
                item+=value[k];
        }
        max_item=max(max_item,item);
    }
    cout<<max_item<<'\n';
    return 0;
}
