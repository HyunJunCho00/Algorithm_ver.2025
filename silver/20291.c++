#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;
    int n;cin>>n;
    map<string,int>m;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        string ss=s.substr(s.find('.')+1);
        m[ss]++;
    }
    for (auto it : m)
    {
        cout<<it.first<<" "<<it.second<<'\n';
    }
    return 0;
}
