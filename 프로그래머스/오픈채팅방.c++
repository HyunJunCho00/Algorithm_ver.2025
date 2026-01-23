#include<bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> record) 
{
    vector<string>answer;
    unordered_map<string,string>um;
    
    for(string re:record)
    {
        stringstream ss(re);
        string action,id,nickname;
        ss>>action>>id;
        
        if (action!="Leave")
        {
            ss>>nickname;
            um[id]=nickname;
        }
    }
    
    for(string re:record)
    {
        stringstream ss(re);
        string action,id;
        ss>>action>>id;
        
        if (action=="Enter")
            answer.push_back(um[id]+"님이 들어왔습니다.");
        else if (action=="Leave")
            answer.push_back(um[id]+"님이 나갔습니다.");
    }
    return answer;
}
