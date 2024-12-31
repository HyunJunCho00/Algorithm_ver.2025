#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int arr[1001];
int lis[1001];
int binarysearch(int start,int end,int target)
{
    int mid;
    while (start<=end)
    {
        mid=(start+end)/2;
        if (target>lis[mid])
            start=mid+1;
        else
            end=mid-1;
    }
    return start;
}
void solve(int n)
{
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
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
    int sum=0;
    for (int i=0;i<count;i++)
    {
        sum+=lis[i];
    }
    cout<<sum<<'\n';
    
}
int main(void)
{
    int n;
    cin>>n;
    solve(n);
    return 0;
}
