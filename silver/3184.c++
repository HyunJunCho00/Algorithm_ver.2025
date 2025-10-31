#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
char board[251][251];
int wolf=0,sheep=0;
int c_wolf=0,c_sheep=0;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
void dfs(int r,int c,vector<vector<bool>>&vis,int s,int e)
{
    vis[s][e]=true;
    for(int i=0;i<4;i++)
    {
        int next_s=s+x[i],next_e=e+y[i];
        if (0<=next_s&&next_s<r&&0<=next_e&&next_e<c&&!vis[next_s][next_e]&&board[next_s][next_e]!='#')
        {
            if (board[next_s][next_e]=='o')
            {
                c_sheep+=1;
            }
            else if (board[next_s][next_e]=='v')
            {
                c_wolf+=1;
            }
            dfs(r,c,vis,next_s,next_e);
        }
    }
}
int main(void)
{
    fastIO;
    int r,c;
    cin>>r>>c;
    for (int i=0;i<r;i++)
    {
        string s;
        cin>>s;
        for(int k=0;k<c;k++)
        {
            board[i][k]=s[k];
        }
    }
    vector<vector<bool>>vis(r,vector<bool>(c,false));
    for(int i=0;i<r;i++)
    {
        for(int k=0;k<c;k++)
        {
            if (!vis[i][k]&&board[i][k]!='#')
            {
                if (board[i][k]=='o')c_sheep+=1;
                else if (board[i][k]=='v')c_wolf+=1;
                dfs(r,c,vis,i,k);
                if (c_wolf>=c_sheep)
                    wolf+=c_wolf;
                else   
                    sheep+=c_sheep;
                c_wolf=0,c_sheep=0;
            }
        }
    }
    cout<<sheep<<' '<<wolf;
    return 0;
}
