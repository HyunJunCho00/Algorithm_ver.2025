#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m;cin>>n>>m;
    vector<int>arr[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    vector<int>dis(n+1,0);
    queue<int>q;
    dis[1]=-1;
    for(int fri:arr[1])
    {
        if (dis[fri]==0)
        {
            dis[fri]=1;
            q.push(fri);
        }    
    }

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(int next:arr[cur])
        {
            if (dis[next]==0) dis[next]=1;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if (dis[i]==1)cnt++;
    cout<<cnt;
    return 0;
}
