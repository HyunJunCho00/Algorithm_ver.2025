#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;int t;cin>>t;
    for (int i=0;i<t;i++)
    {
        int n;cin>>n;
        long long int sum=1+n/2;
        for(int k=n/3;k>=1;k--) sum+=1+(n-k*3)/2;
        cout<<sum<<'\n';
    }
    return 0;
}
