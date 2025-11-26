#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m;
    cin>>n>>m;
    priority_queue<long long int,vector<long long int>,greater<long long int>>pq;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        pq.push(a);
    }
    for(int i=0;i<m;i++)
    {
        long long int a=pq.top();pq.pop();
        long long int b=pq.top();pq.pop();
        long long int s=a+b;
        pq.push(s);pq.push(s);
    }
    long long int res=0;
    while(!pq.empty())
    {
        res+=pq.top();
        pq.pop();
    }
    cout<<res;
    return 0;
}
