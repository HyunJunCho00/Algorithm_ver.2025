#include <bits/stdc++.h>
#define fastIO ios:: sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
vector<int>parent;
int find(int i)
{
    if (i==parent[i])
        return i;
    return parent[i]=find(parent[i]);
}
int main(void)
{
    fastIO;
    int n,m;
    cin>>n>>m;
    parent.assign(n,0);
    for (int i=0;i<n;i++)
        parent[i]=i;
    int idx=0;
    for (int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        int a1=find(a);
        int b1=find(b);
        if (a1==b1&&!idx)
            idx=i;
        else
        {
            if (a1<b1)
                parent[b1]=a1;
            else
                parent[a1]=b1;
        }
    }
    cout<<idx<<'\n';
    return 0;
}
