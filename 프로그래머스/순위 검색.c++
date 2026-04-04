#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string,vector<int>>um;
    
    for(string s:info)
    {
        stringstream ss(s);
        string word[4];
        string score;
        for(int i=0;i<4;i++)
        {
            ss>>word[i];
        }
        ss>>score;
        
        for(int i=0;i<16;i++)
        {
            string key="";
            for(int k=0;k<4;k++)
            {
                if (i&(1<<k)) key+=word[k];
                else key+='-';
            }
            um[key].push_back(stoi(score));
        }
    }
    for(auto &inf:um)
    {
        sort(inf.second.begin(),inf.second.end());
    }
    
    for(string q:query)
    {
        stringstream ss(q);
        string key="",word;
        int score;
        for(int i=0;i<7;i++)
        {
            ss>>word;
            if(word!="and")key+=word;
        }
        ss>>score;
        
        auto&scores=um[key];
        auto it=lower_bound(scores.begin(),scores.end(),score);
        answer.push_back(scores.end()-it);
    }
    return answer;
}
