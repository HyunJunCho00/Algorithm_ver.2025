#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,k;
    cin>>n>>k;
    vector<int>s(n,0);
    for (int i=0;i<n;i++)
        cin>>s[i];
    sort(s.begin(),s.end(),greater<int>());
    cout<<s[k-1]<<'\n';
    return 0;
}
