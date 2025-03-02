#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    int n,a,b,m,x,y,a_cnt=0,b_cnt=0;cin>>n>>a>>b>>m;
    vector<int>pp(n+1,0);
    for(int i=1;i<=n;i++)pp[i]=i;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        pp[y]=x;
    }
    if(a>b)swap(a,b);
    vector<int>save;save.push_back(a);
    while(pp[a]!=a)
    {
        save.push_back(pp[a]);a=pp[a];
    }
    n=0;
    bool ch=false;
    while(pp[b]!=b)
    {
        b_cnt++;
        for(int i=0;i<save.size();i++)
        {
            if (pp[b]==save[i])
            {
                ch=true;n=i;break;
            }
        }
        if (ch)break;
        b=pp[b];
    }
    cout<<(ch?b_cnt+n:-1)<<'\n';
    return 0;
}
///////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,a,b,m,x,y,a_cnt=0,b_cnt=0;cin>>n>>a>>b>>m;
    vector<int>pp(n+1,0),save;
    for(int i=1;i<=n;i++)pp[i]=i;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        pp[y]=x;
    }
    if(a>b)swap(a,b);
    save.push_back(a);
    while(pp[a]!=a)
    {
        save.push_back(pp[a]);a=pp[a];
    }
    while(pp[b]!=b)
    {
        b_cnt++;
        for(int i=0;i<save.size();i++)
        {
            if (pp[b]==save[i])
            {
                cout<<b_cnt+i<<'\n';exit(0);
            }
        }
        b=pp[b];
    }
    cout<<-1<<'\n';
    return 0;
}
