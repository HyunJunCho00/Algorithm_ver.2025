#include<bits/stdc++.h>
using namespace std;
int lis[1001];
int binsearch(int s,int e,int t)
{
    int mid;
    while(s<=e)
    {
        mid=(s+e)/2;
        if (lis[mid]<t)
            s=mid+1;
        else
            e=mid-1;
    }
    return s;
}

int main(void)
{
    int n;cin>>n;
    vector<int>a(n,0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int idx=0;
    for(int i=n-1;i>=0;i--)
    {
        if (i==n-1||lis[idx-1]<a[i])
            lis[idx++]=a[i];
        else
        {
            int id=binsearch(0,idx-1,a[i]);
            lis[id]=a[i];
        }
    }
    cout<<idx;
    return 0;
}
