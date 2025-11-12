#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<bool>dp(n+1,false);
    dp[1]=true;
    dp[3]=true;
    dp[4]=true;
    for(int i=5;i<=n;i++)
    {
        if (!dp[i-4]||!dp[i-3]||!dp[i-1]) dp[i]=true; 
    }
    if (dp[n])cout<<"SK";
    else cout<<"CY";
    return 0;
}
