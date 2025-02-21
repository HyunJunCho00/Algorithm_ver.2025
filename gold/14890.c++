#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,l,s=0,e=n;cin>>n>>l;
    vector<vector<int>>G(n,vector<int>(n,0));
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    for (int i=0;i<n;i++)for(int k=0;k<n;k++)cin>>G[i][k];
    bool ch=true;int path=0;
    for (int i=0;i<n;i++)
    {
        int s=0,e=n;ch=true;
        while (s<e)
        {
            int k=s;
            while(s<e&&G[i][s]==G[i][k])s++;
            if (s==e)break;
            if (G[i][s]>G[i][s-1]+1||G[i][s]+1<G[i][s-1])
            {
                ch=false;break;
            }
            else
            {
                //incline
                if (G[i][s]==G[i][k]+1)
                {
                    if (s-k<l||visited[i][k])
                    {
                        ch=false;break;
                    }
                    for(int z=k;z<s;z++) visited[i][z]=true;
                }
                else
                {
                    //decline
                    k=s;
                    while(s<e&&G[i][s]==G[i][k]&&s-k<l)s++;
                    if (s-k<l)
                    {
                        ch=false;break;
                    }
                    for(int z=k;z<s;z++)visited[i][z]=true;
                    if (s==e)break;
                    if (G[i][k]!=G[i][s])s--;
                }
            }
        }
        if(ch)path++;
        s=0,e=n;ch=true;
        visited.assign(n,vector<bool>(n,false));
        while (s<e)
        {
            int k=s;
            while(s<e&&G[s][i]==G[k][i])s++;
            if (s==e)break;
            if (G[s][i]>G[s-1][i]+1||G[s][i]+1<G[s-1][i])
            {
                ch=false;break;
            }
            else
            {
                //incline
                if (G[s][i]==G[k][i]+1)
                {
                    if (s-k<l||visited[i][k])
                    {
                        ch=false;break;
                    }
                    for(int z=k;z<s;z++) visited[i][z]=true;
                }
                else
                {
                    //decline
                    k=s;
                    while(s<e&&G[s][i]==G[k][i]&&s-k<l)s++;
                    if (s-k<l)
                    {
                        ch=false;break;
                    }
                    for(int z=k;z<s;z++)visited[i][z]=true;
                    if (s==e)break;
                    if (G[s][i]!=G[k][i])s--;
                }
            }
        }
        if(ch)path++;
    }
    cout<<path<<'\n';
    return 0;
}
