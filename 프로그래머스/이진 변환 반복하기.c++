#include<bits/stdc++.h>

using namespace std;
int change(string s)
{
    int c=0;
    for(int i=0;i<s.length();i++)
    {
        if (s[i]=='0')
            c++;
    }
    return c;
}
string convert(string s,int ch)
{
    int con=s.length()-ch;
    string ss="";
    while(con)
    {
        if (con%2)
            ss+="1";
        else
            ss+="0";
        con/=2;
    }
    return ss;
}
vector<int> solution(string s) 
{
    vector<int> answer(2,0);
    while(s!="1")
    {
        int ch=change(s);
        answer[0]++;
        answer[1]+=ch;
        s=convert(s,ch);
    }
    return answer;
}
