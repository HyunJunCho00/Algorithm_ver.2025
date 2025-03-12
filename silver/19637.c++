#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    map<int,string>mm;
    for(int i=0;i<n;i++)
    {
        string s;int t;cin>>s>>t;
        mm.insert({t,s});
    }
    for(int i=0;i<m;i++){
        cin>>n;
        auto it =mm.lower_bound(n);
        cout<<it->second<<'\n';
    }
    return 0;
}
