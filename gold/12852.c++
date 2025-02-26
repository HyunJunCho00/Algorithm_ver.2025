#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 99999999
int y[3]={3,2,1};
using namespace std;
int main(void)
{
    fastIO;int n;cin >> n;
    vector<int> dp(n+1,INF), next(n+1,0);dp[1]=0;
    vector<bool>visited(n+1,false); visited[1]=true;
    queue<int>q;q.push(1);
    while (!q.empty())
    {
        int cur=q.front();q.pop();
        for(int i=0;i<3;i++)
        {
            int go=i<2?cur*y[i]:cur+y[i];
            if(go<=n&&!visited[go]&&dp[go]>dp[cur]){visited[go]=true;dp[go]=dp[cur]+1;next[go]=cur;q.push(go);}
        }
    }
    cout<<dp[n]<<'\n';
    for (int i=n;i>=1;i=next[i])cout<<i<<' ';
    cout<<'\n';
    return 0;
}
