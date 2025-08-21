#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int search(int s,int e,vector<int>&arr,int m,int n)
{
    int ans=0;
    while(s<=e)
    {
        int mid=(s+e)/2,com=0,mm=0;
        for(int i=1;i<=n;i++)
        {
            com+arr[i]>mid?(mm++,com=arr[i]):com+=arr[i];
        }
        mm<m?(ans=mid,e=mid-1):s=mid+1;
    }
    return ans;
}
int main(void)
{
    fastIO;
    int n,m,min_blue=0,mm=0;
    cin>>n>>m;
    vector<int>arr(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        min_blue+=arr[i];
        if (mm<arr[i])mm=arr[i];
    }
    cout<<search(mm,min_blue,arr,m,n);
    return 0;
}
