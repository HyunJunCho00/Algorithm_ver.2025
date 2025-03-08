#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,j=0;cin>>n;
    vector<int>a(n,0),dp;
    for(int i=0;i<n;i++)cin>>a[i];
    dp.push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        if (dp.back()<a[i])
            dp.push_back(a[i]);
        else
        {
            int idx=lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
            dp[idx]=a[i];
        }
    }
    cout<<n-dp.size()<<'\n';
    return 0;
}
