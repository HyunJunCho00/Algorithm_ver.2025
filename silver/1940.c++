#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;int n,m;cin>>n>>m;
    vector <int>j(n,0);
    for(int i=0;i<n;i++)cin>>j[i];
    sort(j.begin(),j.end());
    int s=0,e=n-1,cnt=0;
    while(s<e)
    {
        j[s]+j[e]<m?s++:j[s]+j[e]==m?cnt++,s++:e--;
    }
    cout<<cnt<<'\n';
    return 0;
}
