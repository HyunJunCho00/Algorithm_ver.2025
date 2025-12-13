#include<bits/stdc++.h>
using namespace std;
int lis[2001];
int binsearch(int s,int e,int target)
{
    int mid;
    while(s<=e)
    {
        mid=(s+e)/2;
        if (target>lis[mid])
            s=mid+1;
        else
            e=mid-1;
    }
    return s;
}
void solve(vector<int>&a,int n)
{
    int idx=0;
    for(int i=n;i>=1;i--)
    {
        if (i==n||lis[idx-1]<a[i])
        {
            lis[idx++]=a[i];
        }
        else
        {
            int id=binsearch(0,idx-1,a[i]);
            lis[id]=a[i];
        }
    }
    cout<<n-idx;
}
int main(void)
{
    int n;cin>>n;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    solve(a,n);
    return 0;
}
