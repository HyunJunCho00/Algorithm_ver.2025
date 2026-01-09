#include<bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer=1;
    stack<char>st;
    for (char ss:s)
    {
        if (st.empty())
            st.push(ss);
        else
        {
            char top=st.top();
            if (top==ss)
            {
                st.pop();
            }
            else
            {
                st.push(ss);
            }
        }
    }
    if (!st.empty())answer=0;
    return answer;
}
