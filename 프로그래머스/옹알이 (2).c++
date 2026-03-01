#include<bits/stdc++.h>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    set<string>s;
    s.insert("aya");
    s.insert("ye");
    s.insert("woo");
    s.insert("ma");
    for(string ba:babbling)
    {
        string str="";
        string before="";
        int len=0;
        for(int i=0;i<ba.length();i++)
        {
            str+=ba[i];
            cout<<str<<'\n';
            if (s.find(str)!=s.end()&&before!=str)
            {
                before=str;
                str="";
                len+=before.length();
            }
        }
        if (len==ba.length())answer++;
    }
    return answer;
}
