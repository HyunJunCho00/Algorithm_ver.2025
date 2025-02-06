#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<vector<int>>arr(101,vector<int>(101,0));
    for (int i=0;i<n;i++)
    {
        int x,y;cin>>x>>y;
        for(int k=x;k<x+10;k++)
            for (int l=y;l<y+10;l++)
                arr[k][l]=1;
    }
    int sum=0;
    for (int i=0;i<=100;i++)
        for (int k=0;k<=100;k++)
            if (arr[i][k]==1)
                sum++;
    cout<<sum<<'\n';
    return 0;
}
