#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>>vis(201,vector<bool>(201,false));
vector<int>save;
vector<int> g[201];
bool check=false;
void dfs(int s,int e,vector<bool>&ch)
{
    if (s==e)
    {
        check=true;
        return;
    }
    ch[s]=true;
    for(int gg:g[s])
    {
        if (!ch[gg])
        {
            dfs(gg,e,ch);
        }
    }
}
int main(void)
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
            int a;cin>>a;
            if (a) 
            {
                vis[i][k]=true;
                g[i].push_back(k);
                g[k].push_back(i);
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        int a;cin>>a;
        save.push_back(a);
    }
    for(int i=0;i<m-1;i++)
    {
        if (!vis[save[i]][save[i+1]])
        {
            check=false;
            vector<bool>ch(201,false);
            dfs(save[i],save[i+1],ch);
            if (!check)
            {
                cout<<"NO";exit(0);
            }
        }
    }
    cout<<"YES";
    return 0;
}
