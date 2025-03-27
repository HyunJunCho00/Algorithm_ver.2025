#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        for(int k=0;k<m;k++)
        {
            arr[i][k]=s[k];
        }
    }
    int r=n>m?m:n;
    while(1)
    {
        bool ch=false;
        for(int i=0;i<=n-r;i++)
        {
            for(int k=0;k<=m-r;k++)
            {
                if (arr[i][k]==arr[i+r-1][k]&&arr[i][k+r-1]==arr[i+r-1][k+r-1]&&arr[i][k]==arr[i][k+r-1])ch=true;
            }
        }
        if (ch)break;
        r--;
    }
    cout<<r*r;
    return 0;
}
