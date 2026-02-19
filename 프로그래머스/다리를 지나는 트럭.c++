#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{

    queue<int>q;
    queue<pp>qq;
    for(int i=0;i<truck_weights.size();i++)
        q.push(truck_weights[i]);
    int answer = 1,cur_w=0;
    while(1)
    {
        while(!qq.empty()&&answer-qq.front().second==bridge_length)
        {
            cur_w-=qq.front().first;
            qq.pop();
        }
        if (!q.empty())
        {
            int f=q.front();
            if (cur_w+f<=weight)
            {
                cur_w+=f;
                q.pop();
                qq.push({f,answer});
            }
        }
        if (qq.empty())
            break;
        answer++;
    }
    return answer;
}
