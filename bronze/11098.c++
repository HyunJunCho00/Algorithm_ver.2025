#include<bits/stdc++.h>
using namespace std;
struct Data
{
    long long int p;
    string player;
};
bool comp(const Data&a,const Data&b)
{
    return a.p>b.p;
}
int main(void)
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;cin>>n;
        vector<Data>m;
        for(int k=0;k<n;k++)
        {
            int p;string player;
            cin>>p>>player;
            m.push_back({p,player});
        }
        sort(m.begin(),m.end(),comp);
        cout<<m[0].player<<'\n';
    }
    return 0;
}
