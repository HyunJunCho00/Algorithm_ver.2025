#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
queue<pii>q,w;
vector<vector<char>>arr;
vector<vector<bool>>vis;
void bfs(int r,int c)
{
    bool reach=false;int move=0;
    int w1=0,q1=0,w_size=w.size(),q_size=q.size();
    vis.assign(r,vector<bool>(c,false));
    while(1)
    {
        vector<vector<char>>save=arr;
        int cnt=0;
        ++move;
        for(int i=q1;i<q_size;i++)
        {
            pii cur=q.front();q.pop();
            int x=cur.first,y=cur.second;
            if (arr[x][y]=='*')continue;
            vis[x][y]=true;
            for(int k=0;k<4;k++)
            {
                int cx=x+dx[k],cy=y+dy[k];
                if (0<=cx&&cx<r&&0<=cy&&cy<c&&!vis[cx][cy])
                {
                    if (save[cx][cy]=='.')
                    {
                        q.push({cx,cy});cnt++;vis[cx][cy]=true;save[cx][cy]='S';
                    }
                    else if (save[cx][cy]=='D')
                    {
                        reach=true;break;
                    }
                }
            }
            if (reach)break;
        }
        q1=q_size;q_size+=cnt;
        if (!cnt||reach)break;
        cnt=0;
        for(int i=w1;i<w_size;i++)
        {
            pii cur=w.front();w.pop();
            int x=cur.first,y=cur.second;
            vis[x][y]=true;
            for(int k=0;k<4;k++)
            {
                int cx=x+dx[k],cy=y+dy[k];
                if (0<=cx&&cx<r&&0<=cy&&cy<c)
                {
                    if (!vis[cx][cy]&&(save[cx][cy]!='X'&&save[cx][cy]!='D'))
                    {
                        w.push({cx,cy});cnt++;vis[cx][cy]=true;save[cx][cy]='*';
                    }
                    else if (save[cx][cy]=='S')
                    {
                        w.push({cx,cy});cnt++;save[cx][cy]='*';
                    }
                }
            }
        }
        w1=w_size;w_size+=cnt;
        arr=save;
    }
    if (reach)cout<<move;
    else cout<<"KAKTUS";
}
int main(void)
{
    fastIO;
    int r,c;
    cin>>r>>c;
    arr.assign(r,vector<char>(c));
    int s,e;
    for(int i=0;i<r;i++)
    {
        string s;cin>>s;
        for(int k=0;k<c;k++)
        {
            arr[i][k]=s[k];
            if (s[k]=='S')q.push({i,k});
            else if (s[k]=='*')w.push({i,k});
        }
    }
    bfs(r,c);
    return 0;
}
