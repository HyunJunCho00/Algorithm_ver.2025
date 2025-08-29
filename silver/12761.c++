#include<bits/stdc++.h>
using namespace std;
typedef struct mov
{
    int m,t;
}mov;
bool check(int a,vector<bool>&visited)
{
    return (a>=0&&a<=100000&&!visited[a]);
}
void bfs(int a,int b,int n,int m)
{
    queue<mov> q;
    vector<bool>visited(100001,false);
    q.push({n,0});
    visited[n]=true;
    int next[]={1,-1,a,b,-a,-b};
    while(!q.empty())
    {
        mov cur=q.front();
        q.pop();
        if (cur.m==m)
        {
            cout<<cur.t;break;
        }
        int next_move;
        for(int i=0;i<6;i++)
        {
            next_move=next[i]+cur.m;
            if (check(next_move,visited))
            {
                visited[next_move]=true;
                q.push({next_move,cur.t+1});
            }
            if (i>1&&i<4)
            {
                next_move=next[i]*cur.m;
                if (check(next_move,visited))
                {
                    visited[next_move]=true;
                    q.push({next_move,cur.t+1});
                }
            }    
        }
    }
}
int main(void)
{
    int a,b,n,m;
    cin>>a>>b>>n>>m;
    bfs(a,b,n,m);
    return 0;
}
