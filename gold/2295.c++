#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<int>a(n,0);unordered_set<int>us;
    for(int i=0;i<n;i++)cin>>a[i];
    for (int i=0;i<n;i++)
    {
        for(int k=i;k<n;k++)
        {
            us.insert(a[i]+a[k]);
        }
    }
    sort(a.begin(),a.end());
    for(int i=n-1;i>=1;i--)
    {
        for(int k=i-1;k>=0;k--)
        {
            if (us.find(a[i]-a[k])!=us.end())     
            {
                cout<<a[i]<<'\n';k=-1;i=-1;break;
            }
        }
    }
    return 0;
}
