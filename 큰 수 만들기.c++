#include<bits/stdc++.h>

using namespace std;

string solution(string number, int k) 
{
    
    string answer="";
    stack<char>st;
    for(int i=0;i<number.length();i++)
    {
        char nn=number[i];
        while(!st.empty()&&k>0&&st.top()<nn)
        {
            st.pop();
            k--;
        }
        st.push(nn);
    }
    while(k)
    {
        st.pop();
        k--;
    }
    while(!st.empty())
    {
        answer+=st.top();
        st.pop();
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
