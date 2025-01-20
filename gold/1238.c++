#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 999999999
using namespace std;
typedef struct 
{
    int end;
    int val;

}Data;
struct Comp{
    bool operator()(const Data&a,const Data&b)
    {
        return a.val>b.val;
    }
};
vector <vector<int>>dijk;
vector <Data> arr[1001];
priority_queue<Data,vector<Data>,Comp>pq;
void dijkstra(int n,int x)
{
    dijk.assign(n+1,vector<int>(n+1,INF));
    for (int m=1;m<=n;m++)
    {
        pq.push({m,0});
        dijk[m][m]=0;
        while (!pq.empty())
        {
            Data node=pq.top();
            pq.pop();
            int end=node.end;
            int val=node.val;
            if (dijk[m][end]<val)
                continue;
            for (int i=0;i<arr[end].size();i++)
            {
                int next=arr[end][i].end;
                int weight=arr[end][i].val;
                if (dijk[m][next]>weight+val)
                {
                    dijk[m][next]=weight+val;
                    pq.push({next,dijk[m][next]});
                }
            }
        }
    }
    int result=0;
    for (int m=1;m<=n;m++)
    {
        result=max(result,dijk[m][x]+dijk[x][m]);

    }
    cout<<result<<'\n';
}
int main(void)
{
    int n,m,x;
    cin>>n>>m>>x;
    for (int i=0;i<m;i++)
    {
        int s,e,v;
        cin>>s>>e>>v;
        arr[s].push_back({e,v});
    }
    dijkstra(n,x);
    return 0;
}
