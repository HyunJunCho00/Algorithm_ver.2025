#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
unordered_set<int>s;
void bfs(int a,int b,int n)
{
    vector<bool>vis(n,false);
    queue<pp>q;
    q.push({a,0});
    vis[a]=true;
    while(!q.empty())
    {
        pp p=q.front();
        q.pop();
        if (p.first==b&&s.count(p.first))
        {
            cout<<p.second<<'\n';
            return;
        }
        int k=1000;
        for(int i=k;i<10000;i+=k)
        {
            int com=p.first%k+i;
            if (!vis[com]&&s.count(com))
            {
                vis[com]=true;
                q.push({com,p.second+1});
            }
        }
        for(int i=0;i<3;i++)
        {
            for (int z=0;z<=9;z++)
            {
                int com=(p.first/k)*k+(p.first%(k/10))+z*(k/10);
                if (!vis[com]&&s.count(com))
                {
                    vis[com]=true;
                    q.push({com,p.second+1});
                }
                   
            }
            k/=10;
        }
    }
    cout<<"Impossible\n";
}
int main(void)
{
    int t;cin>>t;
    int n=100001,i=2;
    vector<bool>vis(n,false);
    vis[0]=true,vis[1]=true;
    while(i*i<=n)
    {
        if (!vis[i])
        {
            for(int j=i*i;j<n;j+=i)
            {
                vis[j]=true;
            }
        }
        i+=1;
    }
    for(int i=2;i<n;i++)
    {
        if (!vis[i]&&i>=1000)
            s.insert(i);
    }
    for(int i=0;i<t;i++)
    {
        int a,b;cin>>a>>b;
        bfs(a,b,n);
    }
    return 0;
}
