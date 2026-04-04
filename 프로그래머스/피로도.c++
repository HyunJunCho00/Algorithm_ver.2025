#include<bits/stdc++.h>
using namespace std;
int answer = -1;
void dfs(int k, vector<vector<int>>dungeons,int kk,vector<bool>vis)
{

    if (k==0)
    {
        answer=max(answer,kk);
        return;
    }
    for(int i=0;i<dungeons.size();i++)
    {
        if(!vis[i]&&k-dungeons[i][1]>=0&&k-dungeons[i][0]>=0)
        {
            vis[i]=true;
            dfs(k-dungeons[i][1],dungeons,kk+1,vis);
            vis[i]=false;
        }
    }
    answer=max(answer,kk);
}
int solution(int k, vector<vector<int>> dungeons) {

    vector<bool>vis(dungeons.size(),false);
    dfs(k,dungeons,0,vis);
    return answer;
}
