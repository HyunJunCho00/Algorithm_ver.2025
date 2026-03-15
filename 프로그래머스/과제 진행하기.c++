#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    string name;
    int time, val;
}stt;
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<stt>plan;
    for (int i = 0; i < plans.size(); i++) {

        int h = stoi(plans[i][1].substr(0, 2)) * 60 + stoi(plans[i][1].substr(3, 2));
        int t = stoi(plans[i][2]); 
        plan.push_back({plans[i][0], h, t});
    }

    sort(plan.begin(), plan.end(), [](const stt& a, const stt& b) {
        return a.time < b.time;
    });
    stack<stt>st;
    int cur=0;
    for(int i=0;i<plan.size();i++)
    {
        while(!st.empty()&&cur<plan[i].time)
        {
            stt &task=st.top();
            int diff=plan[i].time-cur;
            if (task.val<=diff)
            {
                cur+=task.val;
                answer.push_back(task.name);
                st.pop();
            }
            else
            {
                task.val-=diff;
                cur=plan[i].time;
            }
            
        }
        st.push(plan[i]);
        cur = plan[i].time;
        
    }
    while(!st.empty())
    {
        answer.push_back(st.top().name);
        st.pop();
    }
    return answer;
}
