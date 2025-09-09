#include<bits/stdc++.h>
using namespace std;
int res=0;
vector<int>st;
void dfs(int s,int n,vector<int>&a,vector<bool>&vis)
{
    if (s==n)
    {
        int com=0;
        for(int i=1;i<n;i++)
        {
            com+=abs(st[i]-st[i-1]);
        }
        if (res<com)res=com;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if (!vis[i])
        {
            vis[i]=true;
            st.push_back(a[i]);
            dfs(s+1,n,a,vis);
            st.pop_back();
            vis[i]=false;
        }
    }
}
int main(void)
{
    int n;cin>>n;
    vector<int>a(n);
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++)cin>>a[i];
    dfs(0,n,a,vis);
    cout<<res;
    return 0;
}
