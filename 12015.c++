#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int lis[1000001];
int arr[1000001];
int binarysearch(int start,int end,int target)
{
    int mid;
    while (start<=end)
    {
        mid=(start+end)/2;
        if (lis[mid]<target)
        {
            start=mid+1;
        }
        else
            end=mid-1;
    }
    return start;
}
void solve(int n)
{
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int count=0;
    for (int i=0;i<n;i++)
    {
        if (i==0||lis[count-1]<arr[i])
            lis[count++]=arr[i];
        else
        {
            int idx=binarysearch(0,count-1,arr[i]);
            lis[idx]=arr[i];
        }
    }
    cout<<count<<'\n';
}
int main(void)
{
    int n;
    cin>>n;
    solve(n);
    return 0;
}
