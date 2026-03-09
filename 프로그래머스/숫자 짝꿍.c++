#include<bits/stdc++.h>
using namespace std;

string solution(string X, string Y) 
{
    string answer = "";
    map<char,int>m;
    for(char x:X)
    {
        m[x]++;
    }
    for(char y:Y)
    {
        if (m[y])
        {
            answer+=y;
            m[y]--;
        }
    }
    sort(answer.begin(),answer.end());
    reverse(answer.begin(),answer.end());
    if (answer.length())
    {
        if (answer[0]=='0')
            return "0";
        return answer;
    }
    else
        return "-1";
}
