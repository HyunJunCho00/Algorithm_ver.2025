#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 2000000001
using namespace std;
int main(void)
{
    fastIO; int n;cin>>n; 
    int res=INF,s=0,e=n-1,ss=0,ee=n-1;
    vector<int>m(n,0);
    for (int i=0;i<n;i++)
        cin>>m[i];
    while (s<e)
    {
        int sum=m[s]+m[e];
        if (res>=abs(sum))
        {
            ss=s,ee=e,res=abs(sum);
        }
        if (sum==0)
        {
            ss=s,ee=e;break;
        }
        else if (sum<0)
            s++;
        else
            e--;
    }
    cout<<m[ss]<<' '<<m[ee]<<'\n';
    return 0;
}
