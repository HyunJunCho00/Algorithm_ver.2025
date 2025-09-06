#include<bits/stdc++.h>
using namespace std;
typedef struct emo
{
    int cur,copy;
}emo;
void bfs(int s)
{
    vector<vector<int>>dist(s+1,vector<int>(s+1,-1));
    queue<emo>q;
    q.push({1,0});
    dist[1][0]=0;
    while(!q.empty())
    {
        emo next=q.front();
        q.pop();
        if (next.cur==s)
        {
            cout<<dist[next.cur][next.copy];break;
        }
        if (next.cur+next.copy<=s&&dist[next.cur+next.copy][next.copy]==-1)
        {
            dist[next.cur+next.copy][next.copy]=dist[next.cur][next.copy]+1;
            q.push({next.cur+next.copy,next.copy});
        }
        if (next.cur-1>=0&&dist[next.cur-1][next.copy]==-1)
        {
            dist[next.cur-1][next.copy]=dist[next.cur][next.copy]+1;
            q.push({next.cur-1,next.copy});
        }
        if (dist[next.cur][next.cur]==-1)
        {
            dist[next.cur][next.cur]=dist[next.cur][next.copy]+1;
            q.push({next.cur,next.cur});
        }
    }    
}
int main(void)
{
    int s;cin>>s;
    bfs(s);
    return 0;
}
