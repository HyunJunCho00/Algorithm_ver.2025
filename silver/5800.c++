#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;cin>>t;
    for(int i=1;i<=t;i++)
    {
        int x,g=0;cin>>x;
        vector<int>a(x);
        for(int k=0;k<x;k++)cin>>a[k];
        sort(a.begin(),a.end());
        for(int k=1;k<x;k++)g=max(g,a[k]-a[k-1]);
        cout<<"Class "<<i<<'\n';
        cout<<"Max "<<a[x-1]<<", "<<"Min "<<a[0]<<", "<<"Largest gap "<<g<<'\n';
    }
    return 0;
}
