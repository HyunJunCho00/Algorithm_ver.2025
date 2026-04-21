#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int i,k,dist;
}node;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<places.size();i++)
    {
        unordered_map<int,pair<int,int>>um;
        int idx=0;
        for(int k=0;k<places[i].size();k++)
        {
            for(int z=0;z<places[i][k].size();z++)
            {
                if (places[i][k][z]=='P')
                {
                    um[idx++]={k,z};
                }
            }
        }
        bool check=true;
        for(auto&umm:um)
        {       
            int r=umm.second.first,h=umm.second.second;
            vector<vector<bool>>vis(places[i].size(),vector<bool>(places[i][0].size(),false));
            queue<node>q;
            q.push({r,h,0});
            vis[r][h]=true;

            while(!q.empty())
            {
                node qq=q.front();
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int nx=qq.i+dx[k],ny=qq.k+dy[k];
                    if(0<=nx&&nx<places[0].size()&&0<=ny&&ny<places.size()&&!vis[nx][ny])
                    {
                        if (qq.dist<2&&places[i][nx][ny]!='X')
                        {
                            if (places[i][nx][ny]=='P')
                            {
                                while(!q.empty())
                                {
                                    q.pop();
                                }
                                check=false;
                                break;
                            }
                            q.push({nx,ny,qq.dist+1});
                        }
                        vis[nx][ny]=true;
                    }
                }
            }
            if (!check)break;
        }
        if(check)answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}
