#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;int n;cin>>n;
    vector<int>arr(n,0);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    int s=0,e=n-1,ss=0,ee=n-1,res=2000000001;
    while (s<e)
    {
        int com=(arr[s]+arr[e]);
        if (res>abs(com))
        {
            res=abs(com);
            ss=s,ee=e;
        }
        if (com<0)
            s++;
        else if (com==0)
        {
            ss=s,ee=e;break;
        }
        else
            e--;
    }
    cout<<arr[ss]<<' '<<arr[ee]<<'\n';
    return 0;
}
