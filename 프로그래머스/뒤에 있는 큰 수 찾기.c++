#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer (numbers.size(),-1);
    stack<pp>st;
    for(int i=0;i<numbers.size();i++)
    {
        if (st.empty())
        {
            st.push({i,numbers[i]});
        }
        else
        {
            while(!st.empty()&&st.top().second<numbers[i])
            {
                answer[st.top().first]=(numbers[i]);
                st.pop();
            }
            st.push({i,numbers[i]});
        }
    }
    while(!st.empty())
    {
        st.pop();
    }
    return answer;
}
