#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
struct Edge
{
    int to;
    int w;
    Edge(int t,int w) : to(t),w(w){}  
};
vector <vector<Edge>> tree;
vector <bool> visited;
int max_dist=0,far_node=0;
void dfs(int i,int dist)
{
    visited[i]=true;
    if (max_dist<dist)
    {
        max_dist=dist;
        far_node=i;
    }
    for (const Edge & e : tree[i])
    {
        if (!visited[e.to])
            dfs(e.to,e.w+dist);    
    }
}
int main(void)
{
    int v;
    cin>>v;
    tree.resize(v+1);
    visited.assign(v+1,false);
    for (int i=0;i<v;i++)
    {
        int idx;
        scanf("%d",&idx);
        int s,e;
        while (1)
        {
            scanf("%d",&s);
            if (s==-1)
                break;
            else
                scanf("%d",&e);
            tree[idx].push_back(Edge(s,e));
        }
    }
    dfs(1,0);
    fill(visited.begin(),visited.end(),false);
    max_dist=0;
    dfs(far_node,0);
    cout<<max_dist<<'\n';
    return 0;
}
