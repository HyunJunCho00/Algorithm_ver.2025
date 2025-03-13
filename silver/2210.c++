#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
queue<pii>q;
queue<int>qq;
queue<int>n;
vector<vector<int>>a;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void bfs()
{
    set<int>s;
    while(!q.empty())
    {
        pii cur=q.front();q.pop();
        int cnt=qq.front();qq.pop();
        int num=n.front();n.pop();
        if (cnt==6)
        {
            s.insert(num);continue;
        }
        int x=cur.first,y=cur.second;
        for(int i=0;i<4;i++)
        {
            int cx=x+dx[i],cy=y+dy[i];
            if (0<=cx&&cx<5&&0<=cy&&cy<5)
            {
                q.push({cx,cy});
                n.push(num*10+a[cx][cy]);
                qq.push(cnt+1);
            }
        }    
    }
    cout<<s.size()<<'\n';
}
int main(void)
{
    a.assign(5,vector<int>(5,0));
    for(int i=0;i<5;i++)
        for(int k=0;k<5;k++)
        {
            cin>>a[i][k];
            q.push({i,k});
            qq.push(1);
            n.push(a[i][k]);
        }
    bfs();
    return 0;
}
