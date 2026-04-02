#include<bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<int,string>m;
    map<string,int>name;
    for(int i=1;i<=players.size();i++)
    {
        m[i]=players[i-1];
        name[players[i-1]]=i;
    }
    for(string call:callings)
    {
        int ind=name[call];
        if (ind>1)
        {
            string comp=m[ind-1];
            m[ind-1]=call;
            m[ind]=comp;
            name[call]=ind-1;
            name[comp]=ind;
        }
    }
    for(auto&res:m)
    {
        answer.push_back(res.second);
    }
    return answer;
}
