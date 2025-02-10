#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;
    unordered_map<long long int,int>m;
    int n;cin>>n;
    for (int i=0;i<n;i++)
    {
        long long int c;cin>>c;
        m[c]++;
    }
    long long int f=0;int cnt=0;
    for (const auto& pair:m)
    {
        if (cnt<pair.second)
        {
            cnt=pair.second;f=pair.first;
        }
        else if (cnt==pair.second&&f>pair.first)
            f=pair.first;
    }
    cout<<f<<'\n';
    return 0;
}
