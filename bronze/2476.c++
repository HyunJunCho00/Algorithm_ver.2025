#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,a,b,c,s=0;cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        a==b&&b==c?s=max(s,10000+a*1000):(a==b||a==c||b==c?s=max(s,1000+(a==b||a==c?a:b)*100):s=max(s,100*max({a,b,c})));
    }
    cout<<s<<'\n';
    return 0;
}
