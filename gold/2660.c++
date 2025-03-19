#include<bits/stdc++.h>
using namespace std;
int graph[51][51];
map<int,vector<int>>m;
void sol(int n)
{
    for(int i=1;i<=n;i++)
    {
        vector<int>dist(n+1,-1);
        queue<int>q;
        dist[i]=0;
        q.push(i);
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            for(int j=1;j<=n;j++)
            {
                if (graph[cur][j]&&dist[j]==-1)
                {
                    dist[j]=dist[cur]+1;
                    q.push(j);
                }
            }
        }
        int max_dist=0;
        for(int j=1;j<=n;j++) max_dist=max(max_dist,dist[j]);
        m[max_dist].push_back(i);
    }
    int idx=0;
    while(1)
    {
        if (m[++idx].size()>=1)break;
    }
    cout<<idx<<' '<<m[idx].size()<<'\n';
    sort(m[idx].begin(),m[idx].end());
    for(int mm:m[idx])
    {
        cout<<mm<<' ';
    }
}
int main(void)
{
    int n;cin>>n;
    int s=0,e=0;
    while(1)
    {
        cin>>s>>e;
        if(s==-1&&e==-1)break;
        graph[s][e]=1;graph[e][s]=1;
    }
    sol(n);
    return 0;
}
