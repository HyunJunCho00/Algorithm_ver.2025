#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int sc:score)
    {
        if (pq.size()<k)
        {
            pq.push(sc);
        }
        else
        {
            vector<int>save;
            while(!pq.empty()&&pq.top()<=sc)
            {
                save.push_back(pq.top());
                pq.pop();
            }
            if (pq.size()<k)
                pq.push(sc);
            reverse(save.begin(),save.end());
            for(int sa:save)
            {
                //cout<<sc<<' '<<pq.top()<<' '<<pq.size()<<' '<<sa<<'\n';
                if (pq.size()<k)pq.push(sa);
                else break;
            }
        }
        answer.push_back(pq.top());
    }
    return answer;
}
