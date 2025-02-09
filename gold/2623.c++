#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
vector<vector<int>>adj;
vector<bool>visited;
vector<int>order;
vector<bool>inpro;
bool cycle=false;
void dfs(int i,int n)
{
    visited[i]=true; inpro[i]=true;
    for (int node:adj[i])
    {
        if (node!=0)
        {
            if (!visited[node])
                dfs(node,n);   
            else if (inpro[node])
                cycle=true;
        }
    }
    inpro[i]=false;
    order.push_back(i);
}
int main(void)
{
    fastIO;int n,m;cin>>n>>m;
    visited.assign(n+1,false);
    adj.resize(n+1);
    inpro.assign(n+1,false);
    for (int i=0;i<m;i++)
    {
        int s;cin>>s;
        vector<int>save(s,0);
        for (int k=0;k<s;k++)
            cin>>save[k];
        for (int k=0;k<s-1;k++)
            adj[save[k]].push_back(save[k+1]);
    }
    for (int i=1;i<=n;i++)
        if (!visited[i])
            dfs(i,n);
    reverse(order.begin(),order.end());
    if(cycle)
        cout<<0<<'\n';
    else
    {
        for (int p:order)
            cout<<p<<'\n';
    }
    return 0;
}
