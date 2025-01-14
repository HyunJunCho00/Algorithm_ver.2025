#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main(void)
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr;
    arr.assign(m+1,vector<int>(n+1,0));
    for (int k=1;k<=n;k++)
    {
        arr[0][k]=k;
    }
    for (int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int a1=a;
        for (int z=c;z<=b;z++)
        {
            arr[i][a1++]=arr[i-1][z];
        }
        for (int z=a;z<=c-1;z++)
        {
            arr[i][a1++]=arr[i-1][z];
        }
        for (int z=1;z<a;z++)
        {
            arr[i][z]=arr[i-1][z];
        }
        for (int z=b+1;z<=n;z++)
        {
            arr[i][z]=arr[i-1][z];
        }
    }
    for (int i=1;i<=n;i++)
    {
        cout<<arr[m][i]<<' ';
    }
    cout<<'\n';
    return 0;
}
