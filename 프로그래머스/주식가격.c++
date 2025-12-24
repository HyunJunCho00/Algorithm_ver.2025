#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    stack<pp>st;
    for(int i=0;i<prices.size();i++)
    {
        if (st.empty())
        {
            st.push({prices[i],i});
        }
        else
        {
            while(!st.empty())
            {
                pp top=st.top();
                if (top.first>prices[i])
                {
                    answer[top.second]=i-top.second;
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            st.push({prices[i],i});
        }
    }
    while(!st.empty())
    {
        pp top=st.top();
        st.pop();
        answer[top.second]=prices.size()-top.second-1;
    }
    return answer;
}
