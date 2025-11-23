#include<bits/stdc++.h>
using namespace std;
set<string>t;
void dfs(int n,int k,int d,vector<int>&arr,vector<int>&save,vector<bool>&vis)
{
    if (k==d)
    {
        string s="";
        for(int ss:save)
            s+=to_string(ss);
        if (!t.count(s)) t.insert(s);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if (!vis[i])
        {
            vis[i]=true;
            save.push_back(arr[i]);
            dfs(n,k,d+1,arr,save,vis);
            save.pop_back();
            vis[i]=false;
        }
    }
}
int main(void)
{
    int n,k;cin>>n>>k;
    vector<int>arr(n,0);
    vector<int>save;
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++)cin>>arr[i];
    dfs(n,k,0,arr,save,vis);
    cout<<t.size();
    return 0;
}
