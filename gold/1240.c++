#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
struct tree
{
    int e,w;
};
vector<tree>graph[1001];
void dfs(vector<bool>&visited,int s,int e,int w)
{
    visited[s]=true;
    if (s==e)
    {
        visited[e]=true; cout<<w<<'\n'; return;
    }
    else
    {
        for(tree g:graph[s])
        {
            if (!visited[g.e])
                dfs(visited,g.e,e,g.w+w);
        }
    }
}
int main(void)
{
    fastIO;int n,m;cin>>n>>m;
    for (int i=0;i<n-1;i++)
    {
        int s,e,w;
        cin>>s>>e>>w;
        graph[s].push_back({e,w}); graph[e].push_back({s,w});
    }
    for(int i=0;i<m;i++)
    {
        vector<bool>visited(n+1,false);
        int s,e;cin>>s>>e;
        dfs(visited,s,e,0);
    }
    return 0;
}
