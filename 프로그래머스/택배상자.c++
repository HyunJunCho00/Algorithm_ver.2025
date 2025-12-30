#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> order) 
{
    stack<int>s;
    int answer = 0,idx=1;
    while(idx<=order.size())
    {
        s.push(idx);
        while(!s.empty()&&s.top()==order[answer])
        {
            answer++;
            s.pop();
        }
        idx++;
    }
    return answer;
}
