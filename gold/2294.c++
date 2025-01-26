#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
vector <int>coin;
vector<int> dp;
int main(void)
{
    fastIO;
    int n,k;
    cin>>n>>k;
    coin.assign(n,0);
    dp.assign(100001,0);
    for (int i=0;i<n;i++)
    {
        cin>>coin[i];
        dp[coin[i]]=1;
    }
    for (int m=1;m<=k;m++)
    {
        for (int l=0;l<n;l++)
        {
            int idx=m-coin[l];
            if (idx>=0&&idx<=k&&dp[idx])
            {
                if (dp[m])
                {
                    dp[m]=min(dp[m],dp[idx]+1);
                }
                else
                {
                    dp[m]=dp[idx]+1;
                }
            }
        }
    }
    int result=dp[k]?dp[k]:-1;
    cout<<result<<'\n';
    return 0;
}
