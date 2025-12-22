#include<bits/stdc++.h>
using namespace std;
void dfs(int s,int n,vector<vector<int>>&computers,vector<bool>&vis)
{
    vis[s]=true;
    for(int i=0;i<=n-1;i++)
    {
        if (!vis[i]&&computers[s][i])
        {
            dfs(i,n,computers,vis);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool>vis(n,false);
    for(int i=0;i<=n-1;i++)
    {
        if (!vis[i])
        {
            dfs(i,n,computers,vis);
            answer++;
        }
    }
    return answer;
}
