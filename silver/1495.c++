#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,s,m;cin>>n>>s>>m;
    vector<int>q(n,0);
    for(int i=0;i<n;i++)cin>>q[i];

    vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
    vis[0][s]=true;
    for(int i=1;i<=n;i++)
    {
       for(int k=0;k<=m;k++)
       {
            if (vis[i-1][k])
            {
                int ss=k-q[i-1];int sss=k+q[i-1];
                if (ss>=0&&!vis[i][ss]) vis[i][ss]=true;
                if (sss<=m&&!vis[i][sss])vis[i][sss]=true;
            }
       } 
    }
    int res=-1;
    for(int mm=m;mm>=0;mm--)
    {
        if (vis[n][mm]&&res<mm)res=mm;
    }
    cout<<res;
    return 0;
}
