#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
int answer = 0;
void dfs(int infection,int k,vector<vector<pp>>&graph,int depth,vector<int>&order)
{
    if (depth==k)
    {
        unordered_set<int>us;
        us.insert(infection);
        for(int type:order)
        {
            queue<int>q;
            for(int now:us)q.push(now);
            while(!q.empty())
            {
                int cur=q.front();
                q.pop();
                for(auto&g:graph[cur])
                {
                    if(type==g.second&&us.find(g.first)==us.end())
                    {
                        q.push(g.first);
                        us.insert(g.first);
                    }
                }
            }
        }
        if(answer<us.size())
            answer=us.size();
        return;
    }
    for(int i=1;i<=3;i++)
    {
        order.push_back(i);
        dfs(infection,k,graph,depth+1,order);
        order.pop_back();
    }
}
int solution(int n, int infection, vector<vector<int>> edges, int k) 
{

    vector<vector<pp>> graph(n+1);
    for(int i=0;i<edges.size();i++)
    {
        graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    vector<int>order;
    dfs(infection,k,graph,0,order);
    return answer;
}
