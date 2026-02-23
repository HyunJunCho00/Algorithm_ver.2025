#include<bits/stdc++.h>
#define pp pair<int,int>
#define INF 1e9
using namespace std;

int dijk(int N,int K,vector<pp>adj[])
{
    vector<int>dist(N+1,INF);
    priority_queue<pp,vector<pp>,greater<pp>>pq;
    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty())
    {
        int w=pq.top().first,u=pq.top().second;
        pq.pop();
        if (dist[u]<w)continue;

        for(auto & ad:adj[u])
        {
            int next=ad.first,weight=ad.second,next_w=w+weight;
            if (next_w<dist[next])
            {
                pq.push({next_w,next});
                dist[next]=next_w;
            }
        }
    }
    int res=0;
    for(int i=1;i<=N;i++)
    {
        if (dist[i]<=K)
            res++;
    }
    return res;
}
int solution(int N, vector<vector<int>> road, int K) 
{
    vector<pp>adj[51];
    for(int i=0;i<road.size();i++)
    {
        adj[road[i][0]].push_back({road[i][1],road[i][2]});
        adj[road[i][1]].push_back({road[i][0],road[i][2]});
    }
    return dijk(N,K,adj);

}
