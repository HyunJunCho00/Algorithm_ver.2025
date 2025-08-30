#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,l,res=0,s=0,e=0;
    cin>>n>>l;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    while(e<n)
    {
        while(e<n&&s<n&&arr[e]-arr[s]<l)e++;
        res++;
        s=e;
    }
    cout<<res;
    return 0;
}
