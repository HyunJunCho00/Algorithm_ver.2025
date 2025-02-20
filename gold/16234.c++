#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int,int>
using namespace std;
vector<vector<int>>A;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void bfs(int n,int l,int r)
{
    int cnt=0;
    while (1)
    {
        bool move=false;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        vector<vector<int>>B(n,vector<int>(n,0));
        queue <pii> q;
        for (int i=0;i<n;i++)
        {
            for (int k=0;k<n;k++)
            {
                if (!visited[i][k])
                {
                    queue<pii>save; int sum=A[i][k]; visited[i][k]=true;
                    q.push({i,k}); save.push({i,k});
                    while (!q.empty())
                    {
                        int x=q.front().first,y=q.front().second;
                        q.pop();
                        for (int z=0;z<4;z++)
                        {
                            int cx=x+dx[z],cy=y+dy[z];
                            if (0<=cx&&cx<n&&0<=cy&&cy<n&&!visited[cx][cy])
                            {
                                int dif=abs(A[cx][cy]-A[x][y]);
                                if (l<=dif&&dif<=r)
                                {
                                    q.push({cx,cy});
                                    save.push({cx,cy});
                                    visited[cx][cy]=true;
                                    sum+=A[cx][cy];
                                    move=true;
                                }
                            }
                        }
                    }
                    int size=save.size();
                    while(!save.empty())
                    {
                        int x=save.front().first,y=save.front().second;
                        save.pop();
                        B[x][y]=sum/size;
                    }
                }
            }
        }
        if (!move)
            break;
        cnt++;
        A=B;
    }
    cout<<cnt<<'\n';
}
int main(void)
{
    fastIO;int n,l,r;cin>>n>>l>>r;
    A.assign(n,vector<int>(n,0));
    for (int i=0;i<n;i++)for(int k=0;k<n;k++)cin>>A[i][k];
    bfs(n,l,r);
    return 0;
}
