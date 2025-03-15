#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>arr;
set<int>res;
vector<int>save;
vector<bool>vis,path;
void dfs(int x)
{
    vis[x]=true;
    path[x]=true;
    save.push_back(x);
    int next=arr[1][x];
    if (!vis[next])
        dfs(next);
    else if (path[next])
    {
        for(int i=0;i<save.size();i++)
        {
            if (save[i]==next)
            {
                res.insert(save.begin()+i,save.end());
                break;
            }
        }
    }
    path[x]=false;
    save.pop_back();
}
int main(void)
{
    int n;cin>>n;
    arr.assign(2,vector<int>(n+1,0));
    
    for(int i=1;i<=n;i++)
    {
        arr[0][i]=i;
        cin>>arr[1][i];
    }
    vis.assign(n+1,false);
    path.assign(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    cout<<res.size()<<'\n';
    for(int s:res)cout<<s<<'\n';
    return 0;
}
