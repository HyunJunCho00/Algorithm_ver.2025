#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using namespace std;
int main(void)
{
    fastIO;int n,k;cin>>n>>k;
    vector<pii>g;
    for (int i=0;i<k;i++)
    {
        int j,s;cin>>j>>s;g.push_back({j,s});
    }
    vector<int>dp(n+1,0);
    for(int i=0;i<k;i++)
    {
        for(int z=n;z>=g[i].second;z--)
        {
            if (dp[z]<dp[z-g[i].second]+g[i].first)
                dp[z]=dp[z-g[i].second]+g[i].first;
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}
