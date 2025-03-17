#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        int p,q,r;
        long long int res=0;
        cin>>p>>q>>r;
        res=min(q,r)+p-1%1000000007;
        cout<<res<<'\n';
    }
    return 0;
}
