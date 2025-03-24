#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        vector<int>a(5);
        int s=0;
        for(int k=0;k<5;k++)cin>>a[k];
        sort(a.begin(),a.end());
        s=a[1]+a[2]+a[3];
        if (a[3]-a[1]<4)cout<<s<<'\n';
        else cout<<"KIN\n";
    }
    return 0;
}
