#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef struct point
{
    int x,y,z;
}point;
int dL[]={1,-1,0,0,0,0};
int dR[]={0,0,1,-1,0,0};
int dC[]={0,0,0,0,1,-1};
void bfs(vector<vector<vector<char>>> &build,vector<vector<vector<int>>> &dist
, vector<vector<vector<bool>>> &visited,point s,point e,int L,int R,int C)
{
    queue<point>q;
    q.push({s.x,s.y,s.z});
    dist[s.x][s.y][s.z]=0;
    visited[s.x][s.y][s.z]=true;
    while(!q.empty())
    {
        point cur=q.front();
        q.pop();
        for(int i=0;i<6;i++)
        {
            int nL=cur.x+dL[i],nR=cur.y+dR[i],nC=cur.z+dC[i];
            if (nL>=0&&nL<L&&nC>=0&&nC<C&&nR>=0&&nR<R)
            {
                if (!visited[nL][nR][nC]&&build[nL][nR][nC]!='#')
                {
                    dist[nL][nR][nC]=dist[cur.x][cur.y][cur.z]+1;
                    visited[nL][nR][nC]=true;
                    if (dist[e.x][e.y][e.z]>0)
                    {
                        cout<<"Escaped in "<<dist[e.x][e.y][e.z]<<" minute(s).\n";
                        return;
                    }
                    q.push({nL,nR,nC});
                }       
            }       
        }
    }
    cout<<"Trapped!\n";    
}
int main(void)
{
    fastIO;
    while(1)
    {
        int L,R,C;
        cin>>L>>R>>C;
        if (!(L|R|C))break;
        vector<vector<vector<char>>> build(L,vector<vector<char>>(R,vector<char>(C)));
        vector<vector<vector<int>>> dist(L,vector<vector<int>>(R,vector<int>(C,-1)));
        vector<vector<vector<bool>>> visited(L,vector<vector<bool>>(R,vector<bool>(C,false)));
        point s,e;
        for(int i=0;i<L;i++)
        {
            for (int k=0;k<R;k++)
            {
                string ss;
                cin>>ss;
                for(int c=0;c<C;c++)
                {
                    build[i][k][c]=ss[c];
                    if (ss[c]=='S')
                    {
                        s={i,k,c};
                    }
                    else if (ss[c]=='E')
                    {
                        e={i,k,c};
                    }
                }
            }
        }
        bfs(build,dist,visited,s,e,L,R,C);
    }
    return 0;
}
