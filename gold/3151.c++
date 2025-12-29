#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<int>arr(n);
    unordered_map<int,vector<int>>um;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        um[arr[i]].push_back(i);
    }

    long long res=0;
    for(int i=0;i<n-2;i++)
    {
        for(int k=i+1;k<n-1;k++)
        {
            int s=-(arr[i]+arr[k]);
            if (um.count(s))
            {
                auto it=upper_bound(um[s].begin(),um[s].end(),k);
                res+=distance(it,um[s].end());
            }
        }
    }
    cout<<res;
    return 0;
}
