#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    long long res=2000000000;
    int s=0,e=n-1;
    while(s<e)
    {
        long long int comp=a[s]+a[e];
        if (abs(res)>=abs(comp))res=comp;
        if (comp==0)break;
        else if (comp<0)s++;
        else e--;
    }
    cout<<res;
    return 0;
}
