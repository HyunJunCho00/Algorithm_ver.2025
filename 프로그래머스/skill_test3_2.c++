#include<bits/stdc++.h>
using namespace std;
int union_find(vector<int>&vis,int d)
{
    if (vis[d]==d)
        return d;
    return union_find(vis,vis[d]);
}
int kryus(vector<int>&vis,vector<vector<int>>&costs,int n)
{
    set<int>s;
    int cost=0;
    for(int i=0;i<costs.size();i++)
    {
        int a=costs[i][0],b=costs[i][1],w=costs[i][2];
        int parent_a=union_find(vis,a);
        int parent_b=union_find(vis,b);
        if (parent_a!=parent_b)
        {
            if (parent_a>parent_b)
            {
                vis[parent_a]=parent_b;

            }
            else
            {
                vis[parent_b]=parent_a;
            }
            cost+=w;
            s.insert(a);
            s.insert(b);
        }
    }
    return cost;
}
int solution(int n, vector<vector<int>> costs) 
{
    sort(costs.begin(),costs.end(),[](const vector<int>& a, const vector<int>& b)    {
        return a.back() < b.back(); 
    });
    vector<int>vis(n,0);
    for(int i=0;i<n;i++) vis[i]=i;
    return kryus(vis,costs,n);
}
