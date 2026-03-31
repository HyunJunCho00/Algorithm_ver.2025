#include<bits/stdc++.h>
using namespace std;
int answer = 0;
void dfs(int sheep,int wolf,vector<int>v,vector<int> info,vector<int> g[])
{
    answer=max(answer,sheep);
    for(int i=0;i<v.size();i++)
    {
        int cur=v[i];
        int next_sheep=(info[cur])?sheep:sheep+1;
        int next_wolf=(info[cur])?wolf+1:wolf;
        if (next_wolf>=next_sheep)continue;
        
        vector<int>vv=v;
        vv.erase(vv.begin()+i);
        for(int gg:g[cur])
        {
            vv.push_back(gg);
        }
        dfs(next_sheep,next_wolf,vv,info,g);
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    vector<int>v;
    vector<int>g[18];
    for(int i=0;i<edges.size();i++)
    {
        int s=edges[i][0],e=edges[i][1];
        g[s].push_back(e);
        if (!s)
        {
            v.push_back(e);
        }
    }
    dfs(1,0,v,info,g);
    return answer;
}
