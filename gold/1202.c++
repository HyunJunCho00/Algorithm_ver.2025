#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using namespace std;
int main(void)
{
    fastIO;int n,k,m,v,idx=0;cin>>n>>k;
    long long int sum=0;
    vector<pii>val;
    vector<bool>visited(n,false);
    vector<int>bag(k);
    priority_queue<int>pq;
    for (int i=0;i<n;i++)
    {
        cin>>m>>v;
        val.push_back({m,v});
    }
    sort(val.begin(),val.end());
    for (int i=0;i<k;i++)cin>>bag[i];
    sort(bag.begin(),bag.end());
    for (int i=0;i<k;i++)
    {
        while (idx<n&&bag[i]>=val[idx].first)
        {
            pq.push(val[idx].second);idx++;
        }
        if (!pq.empty())
        {
            sum+=pq.top();pq.pop();
        }
    }
    cout<<sum<<'\n';
    return 0;
}
