#include <bits/stdc++.h>
#include <queue>
using namespace std;
vector <vector<int>> arr;
vector <vector<bool>> visited;
queue <pair<int,int>> q;
int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
void bfs(int max_size,int n)
{
    int result=0;
    for (int rain=0;rain<=max_size;rain++)
    {
        int area=0;
        for (int i=0;i<n;i++)
        {
            for (int k=0;k<n;k++)
            {
                if (arr[i][k]>rain&&!visited[i][k])
                {
                    area++;
                    q.push(make_pair(i,k));
                    visited[i][k]=true;
                    while (!q.empty())
                    {
                        int x=q.front().first,y=q.front().second;
                        q.pop();
                        for (int d=0;d<4;d++)
                        {
                            int x1=x+dir[d][0],y1=y+dir[d][1];
                            if (x1>=0&&x1<n&&y1>=0&&y1<n)
                            {
                                if (arr[x1][y1]>rain&&!visited[x1][y1])
                                {
                                    visited[x1][y1]=true;
                                    q.push(make_pair(x1,y1));
                                }
                            }
                        }
                    }
                }
            }
        }
        result=max(result,area);
        for (int i = 0; i < visited.size(); i++) {
            fill(visited[i].begin(), visited[i].end(), false);
        }
    }
    cout<<result<<'\n';
}
int main(void)
{
    int n;
    cin>>n;
    arr.resize(n,vector<int>(n,0));
    visited.resize(n,vector<bool>(n,false));
    int max_size=0;
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<n;k++)
        {
            cin>>arr[i][k];
            max_size=max(max_size,arr[i][k]);
        }
    }
    bfs(max_size,n);
    return 0;
}
