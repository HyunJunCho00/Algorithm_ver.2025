#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 999999999
using namespace std;
struct Data
{
    int e,cost;
    bool operator>(const Data&other)const
    {
        return cost>other.cost;
    }
};
vector<vector<Data>>adj(50001);
void dij(int n)
{
    vector<int>dist(n+1,INF); dist[1]=0;
    priority_queue<Data,vector<Data>,greater<Data>>q; q.push({1,0});
    while(!q.empty())
    {
        Data now=q.top();q.pop();
        if (now.cost>dist[now.e])continue;
        for(Data ad:adj[now.e])
        {
            if (dist[now.e]!=INF&&ad.cost+dist[now.e]<dist[ad.e])
            {
                q.push({ad.e,ad.cost});dist[ad.e]=ad.cost+dist[now.e];
            }
        }
    }
    cout<<dist[n];
}   
int main(void)
{
    fastIO;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dij(n);
    return 0;
}
