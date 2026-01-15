#include<bits/stdc++.h>
using namespace std;

int solution(string s) 
{
    int answer=0;
    for (int i=0;i<s.length();i++)
    {
        stack<char>st;
        for(int k=0;k<s.length();k++)
        {
            char ss=s[(i+k)%s.length()];
            if (st.empty())
            {
                st.push(ss);
            }
            else
            {
                 if ((st.top()=='('&&ss==')')||(st.top()=='['&&ss==']')||(st.top()=='{'&&ss=='}'))
                     st.pop();
                 else
                     st.push(ss);
            }
        }
        if (st.empty())
            answer++;
    }
    
    return answer;
}
