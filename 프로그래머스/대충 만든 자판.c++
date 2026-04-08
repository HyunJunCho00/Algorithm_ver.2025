#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char,vector<int>>m;
    for(int i=0;i<keymap.size();i++)
    {
        int idx=0;
        for(char c:keymap[i])
        {
            m[c].push_back(idx++);
        }
    }
    for(auto&mm:m)
    {
        sort(mm.second.begin(),mm.second.end());
    }
    for(int i=0;i<targets.size();i++)
    {
        int ans=0;
        bool ch=true;
        for(char c:targets[i])
        {
            if (m.find(c)!=m.end())
                ans+=m[c][0]+1;
            else ch=false;
        }
        if (ch) answer.push_back(ans);
        else answer.push_back(-1);
    }
    return answer;
}
