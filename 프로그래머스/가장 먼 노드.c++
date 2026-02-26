#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

int bfs(vector<int>graph[],int n)
{
    vector<bool>vis(n+1,false);
    vector<int>dist(n+1,INF);
    queue<int>q;
    vis[1]=true;
    dist[1]=0;
    for(int s:graph[1])
    {
        q.push(s);
        dist[s]=1;
        vis[s]=true;
    }

    int max_dist=0,res=0;
    while(!q.empty())
    {
        int qq=q.front();
        q.pop();
        for(int s:graph[qq])
        {
            if (!vis[s])
            {

                dist[s]=dist[qq]+1;
                max_dist=max(dist[s],max_dist);
                vis[s]=true;
                q.push(s);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if (max_dist==dist[i])
            res++;
    }
    return res;
}
int solution(int n, vector<vector<int>> edge) 
{
    vector<int>graph[20001];
    for(int i=0;i<edge.size();i++)
    {
        int a=edge[i][0],b=edge[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return bfs(graph,n);
}
