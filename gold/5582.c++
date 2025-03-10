#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0);
    string s,ss;cin>>s>>ss;
    vector<vector<int>>dp(s.length()+1,vector<int>(ss.length()+1));
    int max_size=0;
    for(int i=1;i<=s.length();i++)
    {
        for(int k=1;k<=ss.length();k++)
        {
            if (s[i-1]==ss[k-1])
            {
                dp[i][k]=dp[i-1][k-1]+1;
                max_size=max(max_size,dp[i][k]);
            }
        }
    }
    cout<<max_size<<'\n';
    return 0;
}
