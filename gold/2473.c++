#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 4000000001
using namespace std;
int main(void)
{
    fastIO;int n;cin>>n;vector<long long int>arr(n,0);
    for (int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    long long int res=INF;
    vector<long long int> liq(3,0);
    for (int s=0;s<n-2;s++)
    {
        int m=s+1,e=n-1;
        while (m<e)
        {
            long long int comp=arr[s]+arr[m]+arr[e];
            if (res>abs(comp))
            {
                liq[0]=arr[s],liq[1]=arr[m],liq[2]=arr[e],res=abs(comp);
            }
            if (comp==0)
                break;
            else if (comp>0)
                e--;
            else
                m++;
        }
    }
    cout<<liq[0]<<' '<<liq[1]<<' '<<liq[2]<<'\n';
    return 0;
}
