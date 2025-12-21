#include<bits/stdc++.h>
#define pp pair<string,int>
using namespace std;

int bfs(string begin, string target, vector<string>& words) 
{
    queue<pp>q;
    vector<bool>vis(words.size(),false);
    q.push({begin,0});
    while(!q.empty())
    {
        pp s=q.front();
        q.pop();
        if (s.first==target)
        {
            return s.second;
        }
        for(int i=0;i<words.size();i++)
        {
            if (!vis[i])
            {
                int cnt=0;
                for(int k=0;k<words[i].length();k++)
                {
                    if (words[i][k]!=s.first[k])
                        cnt++;
                }
                if (cnt==1)
                {
                    q.push({words[i],s.second+1});
                    vis[i]=true;
                }
            }
        }
    }
    
    return 0;
}
int solution(string begin, string target, vector<string> words) 
{
    int answer=bfs(begin,target,words);
    return answer;
}
