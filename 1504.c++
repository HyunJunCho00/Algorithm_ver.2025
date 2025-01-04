#include <bits/stdc++.h>
using namespace std;
#define INF 10000000
vector<vector<int>> graph;
vector <int> dist;
vector <bool> visited;
int short_dist(int n)
{
    int u=-1;
    int min_dist=INF;
    for (int i=1;i<=n;i++)
    {
        if (!visited[i]&&min_dist>dist[i])
        {
            min_dist=dist[i];
            u=i;
        }
    }
    return u;
}
void dijkstra(int start,int n)
{
    dist.assign(n+1,INF);
    visited.assign(n+1,false);
    dist[start]=0;
    for (int i=1;i<=n;i++)
    {
        int u=short_dist(n);
        if (u==-1)
            break;
        visited[u]=true;
        for (int v=1;v<=n;v++)
        {
            if (!visited[v]&&graph[u][v]!=INF)
            {
                dist[v]=min(dist[v],dist[u]+graph[u][v]);
            }
        }
    }
}
int main(void)
{
    int n,m;
    cin>>n>>m;
    graph.assign(n+1,vector<int>(n+1,INF));
    cin.ignore();
    for (int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b]=c;
        graph[b][a]=c;
    }
    int s,e;
    cin>>s>>e;
    dijkstra(1,n);
    vector <int> dist_from_1=dist;
    dijkstra(s,n);
    vector <int> dist_from_s=dist;
    dijkstra(e,n);
    vector <int> dist_from_e=dist;
    int route1=dist_from_1[s]+dist_from_s[e]+dist_from_e[n];
    int route2=dist_from_1[e]+dist_from_e[s]+dist_from_s[n];
    int answer=min(route1,route2);
    if (answer<INF)
        cout<<answer<<'\n';
    else
        cout<<-1<<'\n';
    return 0;
}
