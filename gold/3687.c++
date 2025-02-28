#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int fire[10]={6,2,5,5,4,5,6,3,7,6};
int main(void)
{
    fastIO;int t;cin>>t;
    vector<long long int>dp(101,-1);dp[0]=0;
    for(int i=0;i<=100;i++)
    {
        if(i==1)continue;
        for(int k=0;k<10;k++)
        {
            if (fire[k]+i<=100)
            {
                if (dp[i+fire[k]]==-1)
                {
                    if (k==0&&i==0)continue;
                    dp[i+fire[k]]=dp[i]*10+k;
                }
                else
                {
                    dp[i+fire[k]]>dp[i]*10+k?dp[i+fire[k]]=dp[i]*10+k:0;
                }
            }
        }
    }
    for (int i=0;i<t;i++)
    {
        int n;cin>>n;
        cout<<dp[n]<<' ';
        vector<int>max_m;
        while (n)
        {
            n%2?max_m.push_back(3):max_m.push_back(2);
            n%2?n-=3:n-=2;
        }  
        for(int k=0;k<max_m.size();k++)
            cout<<(max_m[k]==3?7:1);
        cout<<'\n';
    }
    return 0;
}
