#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int lis[1001];
int lds[1001];
int arr[1001];
void solve(int n)
{
    for (int i=0;i<n;i++)
        cin>>arr[i];
    for (int i=0;i<n;i++)
    {
        lis[i]=1;
        for (int j=0;j<i;j++)
        {
            if (arr[i]>arr[j])
                lis[i]=max(lis[i],lis[j]+1);
        }
    }
    for (int i=n-1;i>=0;i--)
    {
        lds[i]=1;
        for (int j=n-1;j>i;j--)
        {
            if (arr[i]>arr[j])
                lds[i]=max(lds[i],lds[j]+1);
        }
    }
    int result=0;
    for (int i=0;i<n;i++)
        result=max(result,lis[i]+lds[i]-1);
    cout<<result<<'\n';
}
int main(void)
{
    fastIO;
    int n;
    cin>>n;
    solve(n);
    return 0;
}
