#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 999999999
using namespace std;
struct node
{
    int s,e,d; node (int s,int e,int d):s(s),e(e),d(d){};
};
int main(void)
{
    fastIO;int tc;cin>>tc;
    for (int i=0;i<tc;i++)
    {
        vector<node> arr;
        int n,m,w,s,e,t,c=0;cin>>n>>m>>w;
        for (int k=0;k<m;k++)
        {
            cin>>s>>e>>t;
            arr.push_back(node(s,e,t));
            arr.push_back(node(e,s,t));
        }
        for (int k=0;k<w;k++)
        {
            cin>>s>>e>>t;
            arr.push_back(node(s,e,-t));
        }
        for (int k=1;k<=n;k++)
            arr.push_back(node(0,k,0));
        bool cycle=false; int dist[n+1];
        for (int i=0;i<=n;i++)
            dist[i]=INF;
        dist[0]=0;
        for (int k=0;k<=n;k++)
        {
            for (int j=0;j<arr.size();j++)
            {
                node cur=arr[j];
                if (dist[cur.s]!=INF&&dist[cur.s]+cur.d<dist[cur.e])
                {
                    dist[cur.e]=dist[cur.s]+cur.d;
                    if (k==n)
                        cycle=true;
                }
            }
            if (cycle)
                break;
        }
        cout<<(cycle?"YES":"NO")<<'\n';
    }
    return 0;
}
