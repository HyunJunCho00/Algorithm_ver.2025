#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;
    int n;cin>>n;
    vector<long long int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    n--;
    long long int res=0;
    while(n>=0)
    {
        if (n==0){
            res+=a[n];n--;
        }
        else
        {
            if (a[n]>0&&a[n-1]>0)
            {
                a[n]*a[n-1]>=a[n]+a[n-1]?res+=(a[n]*a[n-1]):res+=a[n]+a[n-1];
                n-=2;
            }
            else if (a[n]<0&&a[n-1]<0)
            {
                n%2?(res+=(a[n]*a[n-1]),n-=2):(res+=a[n],n--);
            }
            else
            {
                if (a[n]==0||a[n-1]==0)
                {
                    if (a[n]>0)res+=a[n];
                    n%2?n-=2:n--;
                }
                else
                {
                    n%2?(res+=a[n]+a[n-1],n-=2):(res+=a[n],n--);
                }
            }
        }
        
    }
    cout<<res;
    return 0;
}
