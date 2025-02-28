#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;int n;cin>>n;
    vector<int>t(n+1,0);
    for (int i=0;i<n;i++)cin>>t[i];
    sort(t.begin(),t.end());
    while (t[n-2]+t[n-1]<=t[n]&&n-->=3);
    cout<<(n>=3?(t[n-2]+t[n-1]+t[n]):-1)<<'\n';
    return 0;
}
