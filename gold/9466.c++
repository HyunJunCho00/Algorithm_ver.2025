#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
vector<int>graph,visited;
int cycle=0;
void dfs(int node)
{
    visited[node]=1;
    if (!visited[graph[node]])
        dfs(graph[node]);
    else
    {
        int next=graph[node],cnt=1;
        if (visited[next]!=2)
        {
            while (next!=node)
            {
                cnt++;next=graph[next];
            }
            cycle+=cnt;
        }
    }
    visited[node]=2;
}
int main(void)
{
    fastIO;int t;cin>>t;
    for (int i=0;i<t;i++)
    {
        int n,x;cin>>n;
        visited.assign(n+1,0); graph.assign(n+1,0);
        for (int k=1;k<=n;k++) cin>>graph[k];
        cycle=0;
        for (int k=1;k<=n;k++)
            if (!visited[k])
                dfs(k);
        cout<<n-cycle<<'\n';
    }
    return 0;
}
