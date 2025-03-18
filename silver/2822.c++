#include<bits/stdc++.h>
using namespace std;
struct Data
{
    int ind,v;
};
bool comp(const Data&a,const Data&b)
{
    return a.v>b.v;
}
int main(void)
{
    vector<Data>v;
    vector<int>n;
    for(int i=0;i<8;i++)
    {
        int k;
        cin>>k;v.push_back({i,k});
    }
    sort(v.begin(),v.end(),comp);
    int sum=0;
    for(int i=0;i<5;i++)
    {
        sum+=v[i].v;
        n.push_back(v[i].ind+1);
    }
    sort(n.begin(),n.end());
    cout<<sum<<'\n';
    for(int i=0;i<5;i++)
        cout<<n[i]<<" ";
    return 0;
}
