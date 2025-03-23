#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<int>rope(n,0);
    for(int i=0;i<n;i++)cin>>rope[i];
    sort(rope.begin(),rope.end());
    int res=0;
    for(int i=0;i<n;i++) res=max(res,rope[i]*(n-i));
    cout<<res;
    return 0;
}
