#include<bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int>pq;
    for(int i=0;i<works.size();i++)
        pq.push(works[i]);
    while(n&&!pq.empty())
    {
        int cur=pq.top();
        pq.pop();
        if (cur-1>0)
            pq.push(--cur);
        n--;
    }
    while(!pq.empty())
    {
        answer+=(pq.top())*(pq.top());
        pq.pop();
    }
    return answer;
}
