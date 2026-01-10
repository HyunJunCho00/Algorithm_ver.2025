#include<bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char,int>m;
    for(int i=0;i<s.length();i++)
    {
        int cnt=-1;
        if (m.count(s[i]))
        {
            cnt=i-m[s[i]];
        }
        m[s[i]]=i;
        answer.push_back(cnt);
    }
    return answer;
}
