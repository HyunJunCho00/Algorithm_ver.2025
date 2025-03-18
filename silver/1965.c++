#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<int>a(n,0),dp;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int x:a)
    {
        auto it=lower_bound(dp.begin(),dp.end(),x);
        if (it==dp.end())
            dp.push_back(x);
        else
            *it=x;
    }
    cout<<dp.size();
    return 0;
}
