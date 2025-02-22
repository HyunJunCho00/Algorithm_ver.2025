#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;int n,c,sum=0;cin>>n;
    priority_queue<int,vector<int>,greater<int>>pq;
    for (int i=0;i<n;i++)
    {
        cin>>c;pq.push(c);
    }
    while (pq.size()>=2)
    {
        int f=pq.top();pq.pop();
        int s=pq.top();pq.pop();
        sum+=f+s;
        pq.push(f+s);
    }
    cout<<(n==1?0:sum)<<'\n';
    return 0;
}
