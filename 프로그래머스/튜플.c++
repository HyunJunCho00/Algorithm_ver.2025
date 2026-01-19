#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
bool compare(const pp&a,const pp&b)
{
    return a.second>b.second;
}
vector<int> solution(string s) 
{
    vector<int> answer; 
    map<int,int>m;
    for(int i=2;i<s.length();i++)
    {
        if (isdigit(s[i]))
        {
            string ss="";
            while(isdigit(s[i]))
            {
                ss+=s[i];
                i++;
            }
            m[stoi(ss)]++;
        }
    }
    vector<pp> ve(m.begin(),m.end());
    sort(ve.begin(),ve.end(),compare);
    for (auto&v:ve)
    {
        answer.push_back(v.first);
    }
    return answer;
}
