#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
    vector<int> answer;
    vector<int> graph[n+1];
    for(int i=0;i<roads.size();i++)
    {
        int a=roads[i][0],b=roads[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int>dist(n+1,INF);
    vector<bool>vis(n+1,false);
    queue<int>q;
    q.push(destination);
    vis[destination]=true;
    dist[destination]=0;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(int g:graph[cur])
        {
            if (!vis[g])
            {
                q.push(g);
                vis[g]=true;
            }
            dist[g]=min(dist[cur]+1,dist[g]);
        }
    }
    for(int s:sources)
    {
        if (dist[s]==INF)
            answer.push_back(-1);
        else
            answer.push_back(dist[s]);
    }
    return answer;
}
