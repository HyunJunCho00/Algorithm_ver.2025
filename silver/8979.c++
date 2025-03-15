#include<bits/stdc++.h>
using namespace std;
struct Data
{
    int ind,a,b,c;
};
bool comp(const Data&d1,const Data&d2)
{
    if (d1.a!=d2.a)return d1.a>d2.a;
    else
    {
        if (d1.b!=d2.b)return d1.b>d2.b;
        else return d1.c>d2.c;
    }
}
int main(void)
{
    int n,m,rank=1,i=0;cin>>n>>m;
    vector<Data>d;
    for(int i=0;i<n;i++)
    {
        int ind,a,b,c;
        cin>>ind>>a>>b>>c;
        d.push_back({ind,a,b,c});
    }
    sort(d.begin(),d.end(),comp);
    while(i<n)
    {
        if (i>0&&d[i-1].a==d[i].a&&d[i-1].b==d[i].b&&d[i-1].c==d[i].c)
            rank=rank;
        else
            rank=i+1;
        if (d[i].ind==m)break;
        i++;
    }
    cout<<rank;
    return 0;
}
