#include<bits/stdc++.h>

using namespace std;

int solution(string t, string p) 
{
    
    int answer = 0;
    for(int i=0;i<=t.length()-p.length();i++)
    {
        string s="";
        for(int k=0;k<p.length();k++)
        {
            s+=t[i+k];
        }
        if (stol(s)<=stol(p))answer++;
    }
    return answer;
}
