#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;
    int a,b;
    cin>>a>>b;
    int s=1,n,m=0;
    while(1)
    {
        n=(s+1)*s/2;
        if (a<=n)
            break;
        s++;
    }
    for (int i=a;i<=b;i++)
    {
        m+=s;
        if (n==i)
        {
            s++;
            n=s*(s+1)/2;
        }
    }
    cout<<m<<'\n';
    return 0;
}
