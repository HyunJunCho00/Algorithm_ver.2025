#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
#define INF 9999999
using namespace std;
vector <pii> chick,home;
vector<vector<int>>dist;
vector<bool>visited;
int min_dist=INF;
void dfs(int d,int s,int m)
{
    if (d==m)
    {
        int comp=0;
        for (int k=0;k<home.size();k++)
        {
            int x1=home[k].first,y1=home[k].second; comp+=dist[x1][y1];
        }
        min_dist=min(min_dist,comp);
    }
    else
    {
        for(int i=s;i<chick.size();i++)
        {
            if (!visited[i])
            {
                visited[i]=true;
                int x=chick[i].first,y=chick[i].second;
                vector<vector<int>>temp=dist;
                for (int k=0;k<home.size();k++)
                {
                    int x1=home[k].first,y1=home[k].second;
                    dist[x1][y1]=min(dist[x1][y1],abs(x-x1)+abs(y-y1));
                }
                dfs(d+1,i,m); 
                visited[i]=false;
                dist=temp;
            }
        }
    }
}
int main(void)
{
    fastIO;int n,m,a;cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<n;k++)
        {
            cin>>a;
            if (a==1)
                home.push_back({i,k});
            else if (a==2)
                chick.push_back({i,k});
        }
    }
    dist.assign(n,vector<int>(n,INF)); visited.assign(chick.size(),false);
    dfs(0,0,m); cout<<min_dist<<'\n';
    return 0;
}
-------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
#define INF 9999999
using namespace std;
vector <pii> chick,home;
vector<int>dist;
vector<bool>visited;
int min_dist=INF;
void dfs(int d,int s,int m)
{
    if (d==m)
    {
        int comp=accumulate(dist.begin(),dist.end(),0);
        min_dist=min(min_dist,comp);
    }
    else
    {
        for(int i=s;i<chick.size();i++)
        {
            if (!visited[i])
            {
                visited[i]=true;
                vector<int>temp=dist;
                int x=chick[i].first,y=chick[i].second;
                for (int k=0;k<home.size();k++)
                {
                    int x1 = home[k].first, y1 = home[k].second;
                    dist[k]=min(dist[k],abs(x-x1)+abs(y-y1));
                }
                dfs(1+d,i,m);
                dist=temp;
                visited[i]=false;
            }
        }
    }
}
int main(void)
{
    fastIO;int n,m,a;cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<n;k++)
        {
            cin>>a;
            if (a==1)
                home.push_back({i,k});
            else if (a==2)
                chick.push_back({i,k});
        }
    }
    dist.assign(home.size(),INF); visited.assign(chick.size(),false);
    dfs(0,0,m); cout<<min_dist<<'\n';
    return 0;
}
