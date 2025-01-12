#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
vector <vector<int>> tree;
vector <bool>visited;
vector <int>parent;
vector <int> depth;
void dfs(int root,int v)
{
    visited[root]=true;
    depth[root]=++v;
    for (int child:tree[root])
    {
        if (!visited[child])
        {
            dfs(child,v);
        }
    }
}
int main(void)
{
    int t;
    cin>>t;
    for (int z=0;z<t;z++)
    {
        int n;
        cin>>n;
        visited.assign(n+1,false);
        parent.assign(n+1,0);
        tree.clear();
        tree.resize(n+1);
        depth.assign(n+1,0);
        for (int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        int a,b;
        for (int i=0;i<n-1;i++)
        {
            cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
            parent[b]=a;
        }
        int root=0;
        for (int i=1;i<=n;i++)
        {
            if (parent[i]==i)
            {
                root=i;break;
            }
        }
        dfs(root,0);
        cin>>a>>b;
        while (depth[a]!=depth[b])
        {
            if (depth[a]>depth[b])
                a=parent[a];
            else
                b=parent[b];
        }
        while (a!=b)
        {
            a=parent[a];
            b=parent[b];
        }
        cout<<a<<'\n';
    }
}
