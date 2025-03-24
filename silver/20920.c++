#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
struct Data
{
    string s;
    int cnt;
    bool operator<(const Data &other){
        if (cnt!=other.cnt)return cnt>other.cnt;
        if (s.length()!=other.s.length())return s.length()>other.s.length();
        return s<other.s;
    }
};
int main(void)
{
    fastIO;
    int n,m;
    cin>>n>>m;
    map<string,int>mm;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        mm[s]++;
    }
    vector<Data>arr;
    for (const auto& a : mm)
    {
        if (a.first.length()>=m)
            arr.push_back({a.first,a.second});
    }
    sort(arr.begin(),arr.end());
    for(Data a:arr)
        cout<<a.s<<'\n';
    return 0;
}
