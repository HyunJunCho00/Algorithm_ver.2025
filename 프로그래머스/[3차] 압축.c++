#include<bits/stdc++.h>

using namespace std;

vector<int> solution(string msg) 
{
    vector<int> answer;
    unordered_map<string,int>um;
    for (int i=0;i<26;i++)
    {
        char a='A'+i;
        um[string(1,a)]=i+1;
    }
    string ss="";
    int idx=27;
    for (char&ms :msg)
    {
        string ch=ss+string(1,ms);
        if (um.find(ch)==um.end())
        {
            answer.push_back(um[ss]);
            um[ch]=idx++;
            ss=string(1,ms);    
        }
        else
        {
            ss=ch;
        }
    }
    answer.push_back(um[ss]);
    return answer;
}
