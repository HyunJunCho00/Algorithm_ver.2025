#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,w=0,l=0;cin>>n;
    string s;
    vector<vector<int>>arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        cin>>s;
        for(int k=0;k<n;k++)s[k]=='.'?arr[i][k]=0:arr[i][k]=1;
    }
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n;k++)
        {
            if (!arr[i][k]&&!vis[i][k])
            {
                int cnt=1;vis[i][k++]=true;
                while(k<n&&!arr[i][k])
                {
                    cnt++;vis[i][k]=true;k++;
                }
                if (cnt>=2)w++;
            }
        }
    }
    vis.assign(n,vector<bool>(n,false));
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n;k++)
        {
            if (!arr[k][i]&&!vis[k][i])
            {
                int cnt=1;vis[k++][i]=true;
                while(k<n&&!arr[k][i])
                {
                    cnt++;vis[k][i]=true;k++;
                }
                if (cnt>=2)l++;
            }
        }
    }
    cout<<w<<' '<<l;
    return 0;
}
