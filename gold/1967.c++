#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef struct
{
    int node;
    int weight;
}tree;
vector <tree> T[10001];
vector <bool> visited;
int diameter=0;
int max_node=1;
void dfs(int start,int length)
{
    visited[start]=true;
    if (diameter<length)
    {
        diameter=length;
        max_node=start;
    }
    for (auto trees:T[start])
    {
        if (!visited[trees.node])
        {
            dfs(trees.node,trees.weight+length);
        }
    }
}
int main(void)
{
    fastIO;
    int n;
    cin>>n;
    visited.assign(n+1,0);
    for (int i=0;i<n-1;i++)
    {
        int s,e,w;
        cin>>s>>e>>w;
        T[s].push_back({e,w});
        T[e].push_back({s,w});
    }
    visited.assign(n+1,0);
    dfs(1,0);
    visited.assign(n+1,0);
    diameter=0;
    dfs(max_node,0);
    cout<<diameter<<'\n';
    return 0;
}
