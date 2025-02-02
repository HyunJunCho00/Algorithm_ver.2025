#include <bits/stdc++.h>
#define fastIO ios:: sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 1001
using namespace std;
vector <int> indeg,dp,times;
vector <int>graph[MAX];
void topology(int e,int n)
{
    queue <int> q;
    for (int i=1;i<=n;i++)
    {
        if (!indeg[i])
            q.push(i);
    }
    while (!q.empty())
    {
        int cur=q.front();
        q.pop();
        for (int next:graph[cur])
        {
            indeg[next]--;
            dp[next]=max(dp[next],dp[cur]+times[next]);
            if (indeg[next]==0)
                q.push(next);
        }
    }
    cout<<dp[e]<<'\n';
}
int main(void)
{
    fastIO;
    int t;
    cin>>t;
    for (int i=0;i<t;i++)
    {
        int n,k,s,e;
        cin>>n>>k;
        dp.assign(n+1,0);
        times.assign(n+1,0);
        indeg.assign(n+1,0);
        for (int m=1;m<=n;m++)
        {
            graph[m].clear();
            cin>>dp[m];
            times[m]=dp[m];
        }
        for (int m=0;m<k;m++)
        {
            cin>>s>>e;
            graph[s].push_back(e);
            indeg[e]++;
        }
        cin>>e;
        topology(e,n);
    }
    return 0;
}
