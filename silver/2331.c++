#include<bits/stdc++.h>
using namespace std;
void dfs(int a,int p,vector<int>&vis,int cnt)
{
    if (vis[a])
    {
        cout<<vis[a]-1;
        exit(0);
    }
    vis[a]=cnt;
    int next_a=0;
    while(a)
    {
        int save_a=1,ten_a=a%10;
        for (int i=0;i<p;i++)
        {
            save_a*=ten_a;
        }
        next_a+=save_a;
        a/=10;
    }
    dfs(next_a,p,vis,cnt+1);
}
int main(void)
{
    int a,p;
    cin>>a>>p;
    vector<int>vis(295246,0);
    dfs(a,p,vis,1);
    return 0;
}
