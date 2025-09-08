#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    map<int,int>m;
    int vis=0,sum=0;
    for(int i=0;i<n;i++)
    {
        i<x?sum+=a[i]:sum=sum-a[i-x]+a[i];         
        if (vis<sum)vis=sum;
        m[sum]++;
    }
    if (vis)
    {
        for(auto& z:m)
        {
            if (vis==z.first) cout<<z.first<<'\n'<<z.second;
        }
    }
    else cout<<"SAD";
    return 0;
}
