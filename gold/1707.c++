#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
bool cycle=false;
void dfs(vector<bool>&visited,vector<set<int>>&arr,vector<int>&save,int i)
{
    visited[i]=true;
    for(int num:arr[i])
    {
        if (!visited[num])
        {
            save[num]=save[i]+1;
            dfs(visited,arr,save,num);
        }
        else if (abs(save[num]-save[i])%2==0) cycle=true;
    }

}
int main(void)
{
    fastIO;int k;cin>>k;
    for(int i=0;i<k;i++)
    {
        int v,e;cin>>v>>e;
        cycle=false;
        vector<bool>visited(v+1,false);
        vector<int>save(v+1,0);
        vector<set<int>>arr(v+1);        
        for(int z=0;z<e;z++)
        {
            int u,x;cin>>u>>x;
            arr[u].insert(x);
            arr[x].insert(u);
        }
        for (int i=1;i<=v;i++)
        {
            if (!visited[i])dfs(visited,arr,save,i);
        }
        cout<<(cycle?"NO\n":"YES\n");
        
    }
    return 0;
}
