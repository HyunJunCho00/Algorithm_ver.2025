#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int res=0;n--;
    while(n>=0)
    {
        if (n>=1)
        {
            if (a[n]>0&&a[n-1]>0)
            {
                a[n-1]*a[n]>=a[n]+a[n-1]?(res+=a[n-1]*a[n]):(res+=a[n]+a[n-1]);
                n-=2;
            }
            else if (a[n]<0&&a[n-1]<0)
            {
                n%2?(res+=(a[n]*a[n-1]),n-=2):(res+=a[n],n-=1);
            }
            else
            {
                if (a[n-1]==0||a[n]==0)
                {
                    if (a[n]>0)res+=a[n];
                    n%2?(n-=2):(n-=1);
                }
                else
                {
                    n%2?(res+=(a[n]+a[n-1]),n-=2):(res+=a[n],n-=1);
                }
            }
        }
        else
        {
            res+=a[n];n--;
        }
    }
    cout<<res;
    return 0;
}
